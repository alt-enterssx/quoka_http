#include "./HttpRouter.h"

std::map<HttpRouter::RequestMap, HttpResponse::Response(*)(HttpRequest::Request)> HttpRouter::router;

HttpRouter::HttpRouter() {}

void HttpRouter::route(HttpRequest::Request req, SOCKET& cSock) {
	auto it = this->router.find(HttpRouter::RequestMap{ req.method, req.url });
	int iSR = 0;
	
	if (it != this->router.end()) {
		HttpResponse::Response resp = it->second(req);
		std::string response = HttpResponse::generateResponse(resp);
		iSR = send(cSock, response.c_str(), response.size(), 0);

		if (iSR == SOCKET_ERROR) {
			closesocket(cSock);
			WSACleanup();
			throw HttpException("Send response is failed");
		}
	} else {
		std::string response = "";
		response += "HTTP/1.1 200 OK \r\n";
		response += "Content-Type: application/json \r\n";
		response += "Connection: close \r\n";
		response += "\r\n";
		response += "{\"name\": \"test\", \"code\": 3030}";

		iSR = send(cSock, response.c_str(), response.size(), 0);
		
		if (iSR == SOCKET_ERROR) {
			closesocket(cSock);
			WSACleanup();
			throw HttpException("Send response is failed");
		}
	}
}

void HttpRouter::GET_M(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) {
	RequestMap reqMap{ HttpRequest::MethodType::GET, url };

	auto it = router.find(reqMap);
	if (it != router.end()) {
		HttpLogger::log(std::string("Handler for ") + url + " is not empty", HttpLogger::LoggerType::ERR);
	} else {
		router[reqMap] = func;
	}

}

void HttpRouter::POST_M(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) {
	RequestMap reqMap{ HttpRequest::MethodType::POST, url };

	auto it = router.find(reqMap);
	if (it != router.end()) {
		HttpLogger::log(std::string("Handler for ") + url + " is not empty", HttpLogger::LoggerType::ERR);
	}
	else {
		router[reqMap] = func;
	}
}

void HttpRouter::PUT_M(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) {
	RequestMap reqMap{ HttpRequest::MethodType::PUT, url };

	auto it = router.find(reqMap);
	if (it != router.end()) {
		HttpLogger::log(std::string("Handler for ") + url + " is not empty", HttpLogger::LoggerType::ERR);
	}
	else {
		router[reqMap] = func;
	}
}

void HttpRouter::HEAD_M(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) {
	RequestMap reqMap{ HttpRequest::MethodType::HEAD, url };

	auto it = router.find(reqMap);
	if (it != router.end()) {
		HttpLogger::log(std::string("Handler for ") + url + " is not empty", HttpLogger::LoggerType::ERR);
	}
	else {
		router[reqMap] = func;
	}
}

void HttpRouter::DELETE_M(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request)) {
	RequestMap reqMap{ HttpRequest::MethodType::DELETE_M, url };

	auto it = router.find(reqMap);
	if (it != router.end()) {
		HttpLogger::log(std::string("Handler for ") + url + " is not empty", HttpLogger::LoggerType::ERR);
	}
	else {
		router[reqMap] = func;
	}
}