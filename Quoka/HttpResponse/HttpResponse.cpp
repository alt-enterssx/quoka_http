#include "./HttpResponse.h"

std::string HttpResponse::generateResponse(HttpResponse::Response& resp) {

	std::string response = "";
	response += std::string(resp.version) + " " + std::to_string(static_cast<int>(resp.type)) + " " + getStatusAsStr(resp.type) + "\r\n";

	if (!resp.headers.empty()) {
		for (int i = 0; i < resp.headers.size(); i++) {
			response += getHeaderAsStr(resp.headers[i].type) + ":" + " " + resp.headers[i].val + "\r\n";
		}
	}

	response += "\r\n";
	response += resp.body.val;

	return response;
}

std::string HttpResponse::getStatusAsStr(HttpResponse::StatusType& type) {
	switch (type) {
		case HttpResponse::StatusType::CONTINUE:
			return "CONTINUE";
		case HttpResponse::StatusType::OK:
			return "OK";
		case HttpResponse::StatusType::CREATED:
			return "CREATED";
		case HttpResponse::StatusType::ACCEPTED:
			return "ACCEPTED";
		case HttpResponse::StatusType::NO_CONTENT:
			return "NO_CONTENT";
		case HttpResponse::StatusType::FOUND:
			return "FOUND";
		case HttpResponse::StatusType::NOT_MODIFIED:
			return "NOT_MODIFIED";
		case HttpResponse::StatusType::USE_PROXY:
			return "USE_PROXY";
		case HttpResponse::StatusType::TEMPORARY_REDIRECT:
			return "TEMPORARY_REDIRECT";
		case HttpResponse::StatusType::PERMANENT_REDIRECT:
			return "PERMANENT_REDIRECT";
		case HttpResponse::StatusType::BAD_REQUEST:
			return "BAD_REQUEST";
		case HttpResponse::StatusType::UNAUTHORIZED:
			return "UNAUTHORIZED";
		case HttpResponse::StatusType::FORBIDDEN:
			return "FORBIDDEN";
		case HttpResponse::StatusType::NOT_FOUND:
			return "NOT_FOUND";
		case HttpResponse::StatusType::METHOD_NOT_ALLOWED:
			return "METHOD_NOT_ALLOWED";
		case HttpResponse::StatusType::CONFLICT:
			return "CONFLICT";
		case HttpResponse::StatusType::INTERNAL_SERVER_ERROR:
			return "INTERNAL_SERVER_ERROR";
		case HttpResponse::StatusType::NOT_IMPLEMENT:
			return "NOT_IMPLEMENT";
		case HttpResponse::StatusType::BAD_GATEWAY:
			return "BAD_GATEWAY";
		case HttpResponse::StatusType::UNKOWN_ERROR:
			return "UNKOWN_ERROR";
		default:
			return "UNKOWN";
	}
}

std::string HttpResponse::getHeaderAsStr(HttpResponse::HeaderType& type) {
	switch (type) {
		case HttpResponse::HeaderType::CONNECTION:
			return "Connection";
		case HttpResponse::HeaderType::DATA:
			return "Data";
		case HttpResponse::HeaderType::LOCATION:
			return "Location";
		case HttpResponse::HeaderType::SERVER:
			return "Server";
		case HttpResponse::HeaderType::SET_COOKIE:
			return "Set-Cookie";
		case HttpResponse::HeaderType::WWW_AUTHENTICATE:
			return "WWW-Authenticate";
		case HttpResponse::HeaderType::ALLOW:
			return "Allow";
		case HttpResponse::HeaderType::CONTENT_TYPE:
			return "Content-Type";
		case HttpResponse::HeaderType::CONTENT_LENGTH:
			return "Content-Length";
		case HttpResponse::HeaderType::UNKOWN_HEADER:
			return "Unkown";

	}
}
