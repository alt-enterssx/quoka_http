#include "./HttpRequest.h"

HttpRequest::Request HttpRequest::parseRequest(std::string& str) {
	if (str.empty()) { throw HttpException("Empty HTTP request"); }

	HttpRequest::Request req{};
	std::vector<std::string> lines = split(str, '\n');

	if (lines.empty() || lines[0].empty()) {
		throw HttpException("Invalid HTTP request: missing start line");
	}

	std::vector<std::string> firstLine = split(lines[0], ' ');
	if (firstLine.size() != 3) {
		throw HttpException("Invalid HTTP request: incorrect start line format");
	}

	try {
		req.method = getMethodAsEn(firstLine[0]);
	}
	catch (HttpException& ex) {
		HttpLogger::log(ex.what(), HttpLogger::LoggerType::ERR);
	}
	req.url = firstLine[1];
	req.version = firstLine[2];

	size_t paramPos = req.url.find('?');
	if (paramPos != std::string::npos) {
		std::string paramStr = req.url.substr(paramPos + 1);
		req.url = req.url.substr(0, paramPos);
		req.params = split(paramStr, '&');
	}

	for (size_t i = 1; i < lines.size(); i++) {
		if (lines[i].empty()) break; 

		size_t pos = lines[i].find(':');
		if (pos != std::string::npos) {
			std::string key = lines[i].substr(0, pos);
			std::string value = lines[i].substr(pos + 1);
			if (!value.empty() && value[0] == ' ') value.erase(0, 1);
			req.headers.push_back(HttpRequest::Header(getHeaderAsEn(key), value));
		}
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
	else if (method == "DELETE") { return HttpRequest::MethodType::DELETE_METHOD; }
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
		case HttpRequest::MethodType::DELETE_METHOD:
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