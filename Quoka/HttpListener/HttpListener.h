#pragma once
#ifndef HTTP_LISTENER_H
#define HTTP_LISTENER_H

#include "../HttpException/HttpException.h"
#include "../ServerProperties/ServerProperties.h"
#include "../HttpLogger/HttpLogger.h"
#include "../HttpRequest/HttpRequest.h"
#include "../HttpRouter/HttpRouter.h"

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#include <iostream>

#define DEFAULT_BUFFER 2042

class HttpListener {

	public:

		HttpListener(SOCKET& lSock);
		~HttpListener();

		void listen();
		void close();

	private:

		SOCKET lSock = INVALID_SOCKET;
		bool worked = 0x1;

};

#endif // !HTTP_LISTENER_H
