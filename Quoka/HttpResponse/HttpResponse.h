#pragma once
#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include <string>
#include <vector>

class HttpResponse {

	public:

		enum StatusType {
			CONTINUE = 100,
			OK = 200,
			CREATED = 201,
			ACCEPTED = 202,
			NO_CONTENT = 204,
			FOUND = 302,
			NOT_MODIFIED = 304,
			USE_PROXY = 305,
			TEMPORARY_REDIRECT = 307,
			PERMANENT_REDIRECT = 308,
			BAD_REQUEST = 400,
			UNAUTHORIZED = 401,
			FORBIDDEN = 403,
			NOT_FOUND = 404,
			METHOD_NOT_ALLOWED = 405,
			CONFLICT = 409,
			INTERNAL_SERVER_ERROR = 500,
			NOT_IMPLEMENT = 501,
			BAD_GATEWAY = 502,
			UNKOWN_ERROR = 520,
			UNKOWN_STATUS = 0
		};

		enum HeaderType {
			CONNECTION = 0x0,
			DATA = 0x1,
			LOCATION = 0x2,
			SERVER = 0x3,
			SET_COOKIE = 0x4,
			WWW_AUTHENTICATE = 0x5,
			ALLOW = 0x6,
			CONTENT_TYPE = 0x7,
			CONTENT_LENGTH = 0x8,
			UNKOWN_HEADER = 0x9
		};

		struct Header {
			HeaderType type;
			std::string val;

			Header(HeaderType type = HeaderType::UNKOWN_HEADER, std::string val = "") : type(type), val(val) {}
		};

		enum BodyType {
			JSON = 0x0,
			HTML = 0x1,
			TEXT = 0x2,
			IMG = 0x3,
			VID = 0x4,
			UNKOWN_BODY = 0x5 
		};

		struct Body {
			BodyType type;
			std::string val;

			Body(BodyType type = BodyType::UNKOWN_BODY, std::string val = "") : type(type), val(val) {}
		};

		struct Response {
			std::string version;
			StatusType type;
			std::vector<Header> headers;
			Body body;

			Response(std::string version = "HTTP/1.1", StatusType type = StatusType::UNKOWN_STATUS, 
				std::vector<Header> headers = {}, Body body = Body{}) 
					: version(version), type(type), headers(headers), body(body) {}
		};

		static std::string generateResponse(Response& resp);

	private:
		static std::string getStatusAsStr(StatusType& type);
		static std::string getHeaderAsStr(HeaderType& type);

};

#endif // !HTTP_RESPONSE_H
