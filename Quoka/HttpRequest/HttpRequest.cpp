#include "./HttpRequest.h"

HttpRequest::Request HttpRequest::parseRequest(std::string& str) {
	if (str.empty()) { throw HttpException("In parse Request"); }
	
	HttpRequest::Request req{};
	std::vector<std::string> lines = split(str, '\n');
	
	std::vector<std::string> firstLine;
	if (!lines.empty() && !lines[0].empty()) {
		try {
			firstLine = split(lines[0], ' ');
		} catch (HttpException& ex) {
			std::string err = ex.what();
			HttpLogger::log(err, HttpLogger::LoggerType::ERR);
		}
	} else {
		throw HttpException("Request vector is empty");
	}

	if (firstLine.size() == 3) {
		try {
			req.method = getMethodAsEn(firstLine[0]);
		} catch (HttpException& ex) {
			std::string err = ex.what();
			HttpLogger::log(err, HttpLogger::LoggerType::ERR);
		}
		req.url = firstLine[1];
		req.version = firstLine[2];
	}

	for (int i = 1; i < lines.size(); i++) {
		if (lines[i][0] != '\r') {
			std::vector<std::string> header = split(lines[i], ':');
			if (header.size() == 2) {
				try {
					req.headers.push_back(HttpRequest::Header(getHeaderAsEn(header[0]), header[1]));
				} catch (HttpException& ex) {
					std::string err = ex.what();
					HttpLogger::log(err, HttpLogger::LoggerType::ERR);
				}
			}
		} else { break; }
	}

	return req;
}

std::vector<std::string> HttpRequest::split(std::string& str, char sym) {
	if (str.empty()) { throw HttpException("In parse Request"); }

	std::vector<std::string> lines;
	std::string line = "";

	for (int i = 0; i < str.size(); i++) {
		if (sym == ':' && str[i] == ' ') continue;
		if (sym == '\n' && str[i] == '\r') continue;
		if (str[i] != sym) {
			line += str[i];
		} else {
			if (line.empty()) continue;
			lines.push_back(line);
			line = "";
		}
	}

	if (!line.empty()) {
		lines.push_back(line);
	}

	return lines;

}

HttpRequest::MethodType HttpRequest::getMethodAsEn(std::string& method) {
	if (method == "GET") { return HttpRequest::MethodType::GET; }
	else if (method == "POST") { return HttpRequest::MethodType::POST; }
	else if (method == "PUT") { return HttpRequest::MethodType::PUT; }
	else if (method == "HEAD") { return HttpRequest::MethodType::HEAD; }
	else if (method == "DELETE") { return HttpRequest::MethodType::DELETE; }
	else { throw HttpException("Method is unkown"); }
}

std::string HttpRequest::getMethodAsStr(HttpRequest::MethodType type) {
	switch (type) {
		case HttpRequest::MethodType::GET:
			return "GET";
		case HttpRequest::MethodType::POST:
			return "POST";
		case HttpRequest::MethodType::PUT:
			return "PUT";
		case HttpRequest::MethodType::HEAD:
			return "HEAD";
		case HttpRequest::MethodType::DELETE:
			return "DELETE";
		default:
			return "";
	}
}

HttpRequest::HeaderType HttpRequest::getHeaderAsEn(std::string& header) {
	if (header == "Accept") { return HttpRequest::HeaderType::ACCEPT; }
	else if (header == "Connection") { return HttpRequest::HeaderType::CONNECTION; }
	else if (header == "Authorization") { return HttpRequest::HeaderType::AUTHORIZATION; }
	else if (header == "Cookie") { return HttpRequest::HeaderType::COOKIE; }
	else if (header == "Host") { return HttpRequest::HeaderType::HOST; }
	else if (header == "Referer") { return HttpRequest::HeaderType::REFERER; }
	else if (header == "Content-Type") { return HttpRequest::HeaderType::CONTENT_TYPE; }
	else if (header == "Content-Length") { return HttpRequest::HeaderType::CONTENT_LENGTH; }
	else { return HttpRequest::HeaderType::UNKOWN_HEADER; }
}

HttpRequest::Header HttpRequest::getHeader(std::vector<HttpRequest::Header> headers, HttpRequest::HeaderType type) {
	for (int i = 0; i < headers.size(); i++) {
		if (headers[i].header == type) {
			return headers[i];
		}
	}
	throw HttpException("Header not found");
}