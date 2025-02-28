#include <iostream>
#include <fstream>
#include <string>

#include "./ServerProperties/ServerProperties.h"
#include "./HttpLauncher/HttpLauncher.h"
#include "./HttpLogger/HttpLogger.h"
#include "./HttpRouter/HttpRouter.h"
#include "./HttpRequest/HttpRequest.h"
#include "./HttpResponse/HttpResponse.h"

int main() {

	HttpRouter::GET_M(std::string("/api/error"), +[](HttpRequest::Request req) -> HttpResponse::Response {
		HttpResponse::Response resp{};

		resp.type = HttpResponse::StatusType::PERMANENT_REDIRECT;
		resp.version = "HTTP/1.1";
		resp.headers.push_back(HttpResponse::Header{ HttpResponse::HeaderType::LOCATION, "localhost:8080/api/test" });

		return resp;
	});

	HttpRouter::GET_M(std::string("/api/test"), +[](HttpRequest::Request req) -> HttpResponse::Response {
		HttpResponse::Response resp{};

		try {

			HttpRequest::Header acceptHeader = HttpRequest::getHeader(req.headers, HttpRequest::HeaderType::ACCEPT);
			if (acceptHeader.val == "application/json") {
				resp.body = HttpResponse::Body{HttpResponse::BodyType::TEXT, "{ \"name\": \"test\" }"};
			} else {
				resp.body = HttpResponse::Body{ HttpResponse::BodyType::TEXT, "test text" };
			}
		} catch (HttpException& ex) {
			std::string err = ex.what();
			HttpLogger::log(err, HttpLogger::ERR);
		}

		resp.headers.push_back(HttpResponse::Header(HttpResponse::HeaderType::CONNECTION, "close"));
		resp.headers.push_back(HttpResponse::Header(HttpResponse::HeaderType::CONTENT_LENGTH, std::to_string(resp.body.val.size())));
		resp.type = HttpResponse::StatusType::OK;
		resp.version = "HTTP/1.1";

		return resp;

	});

	try {
	
		ServerProperties prop;
		std::ifstream file("./server_config.prop");
		prop.setFile(file);

		HttpLauncher launcher;
		launcher.launch();
	
	} catch (HttpException& ex) {
		std::string err = ex.what();
		HttpLogger::log(err, HttpLogger::ERR);
	}

	return 0x0;
}