#pragma once
#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include "../HttpLogger/HttpLogger.h"
#include "../HttpException/HttpException.h"

#include <string>
#include <vector>
#include <iostream>

class HttpRequest {

	public:
		enum MethodType {
			GET = 0x0,
			POST = 0x1,
			PUT = 0x2,
			HEAD = 0x3,
			DELETE = 0x4,
			UNKOWN_METHOD = 0x5
		};

		enum HeaderType {
			ACCEPT = 0x0,
			AUTHORIZATION = 0x1,
			CONNECTION = 0x2,
			CONTENT_LENGTH = 0x3,
			CONTENT_TYPE = 0x4,
			COOKIE = 0x5,
			HOST = 0x6,
			REFERER = 0x7,
			UNKOWN_HEADER = 0x8
		};

		struct Header {
			HeaderType header;
			std::string val;

			Header(HeaderType type = HeaderType::UNKOWN_HEADER, std::string val = "") : header(type), val(val) {}
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
			BodyType body;
			std::string val;

			Body(BodyType type = BodyType::UNKOWN_BODY, std::string val = "") : body(type), val(val) {}
		};

		struct Request {
			MethodType method;
			std::string url;
			std::string version;
			std::vector<Header> headers;
			Body body;

			Request(MethodType type = MethodType::UNKOWN_METHOD, std::string url = "", std::string version = "",
				std::vector<Header> header = {}, Body body = Body{}) 
					: method(type), url(url), version(version), headers(header), body(body) {}
		};

		static Request parseRequest(std::string& str);

		static std::string getMethodAsStr(MethodType type);
		static Header getHeader(std::vector<Header> headers, HeaderType type);

	private:
		static std::vector<std::string> split(std::string& str, char sym);
		
		static HeaderType getHeaderAsEn(std::string& header);
		static MethodType getMethodAsEn(std::string& method);


};

#endif // !HTTP_REQUEST_H
