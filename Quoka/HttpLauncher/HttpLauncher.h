#pragma once
#ifndef HTTP_STARTER_H
#define HTTP_STARTER_H

#define DEFAULT_PORT 8080

#include "../HttpException/HttpException.h"
#include "../ServerProperties/ServerProperties.h"
#include "../HttpListener/HttpListener.h"
#include "../HttpLogger/HttpLogger.h"

#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")

#include <string>
#include <iostream>

class HttpLauncher {

	public:
		HttpLauncher(int port);
		HttpLauncher() noexcept;
		~HttpLauncher() noexcept;

		int getPort();
		void setPort(int port);

		void launch();

	private:

		int port;

		std::string getIp(sockaddr& addr);

};

#endif // !HTTP_STARTER_H
