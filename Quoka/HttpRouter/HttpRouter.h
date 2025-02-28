#pragma once
#ifndef HTTP_ROUTER_H
#define HTTP_ROUTER_H

#include "../HttpRequest/HttpRequest.h"
#include "../HttpResponse/HttpResponse.h"
#include "../HttpLogger/HttpLogger.h"

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#include <string>
#include <map>

class HttpRouter {

	public:
		struct RequestMap {
			HttpRequest::MethodType method;
			std::string url;

			bool operator<(const RequestMap& other) const {
				return std::tie(method, url) < std::tie(other.method, other.url);
			}
		};

		HttpRouter();
		void route(HttpRequest::Request req, SOCKET& cSock);

		static void GET_M(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request));
		static void POST_M(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request));
		static void PUT_M(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request));
		static void HEAD_M(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request));
		static void DELETE_M(const std::string& url, HttpResponse::Response(*func)(HttpRequest::Request));

	private:
		static std::map<RequestMap, HttpResponse::Response(*)(HttpRequest::Request)> router;

};

#endif // !HTTP_ROUTER_H
