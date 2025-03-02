#include "./HttpLauncher.h"

HttpLauncher::HttpLauncher(int port) {
	if (port < 0x0 || port > 0xFFFF) { throw HttpException("ERR::Port in not valid"); }

	this->port = port;
}

HttpLauncher::HttpLauncher() noexcept { this->port = DEFAULT_PORT; }

HttpLauncher::~HttpLauncher() noexcept {}

int HttpLauncher::getPort() { return this->port;  }
void HttpLauncher::setPort(int port) {
	if (port < 0x0 || port > 0xFFFF) { throw HttpException("ERR::Port in not valid"); }

	this->port = port;
}

void HttpLauncher::launch() {

	if (this->port == -1) {

		std::string portProp = ServerProperties::getProperty("server-port");

		std::cout << portProp << '\n';

		if (portProp != "") {
			int res = 0;
			__asm {
				xor eax, eax
				mov esi, portProp
			
			atoi_loop:
				movzx ecx, byte ptr[esi]
					test ecx, ecx
					je atoi_done
					sub ecx, '0'
					imul eax, eax, 10
					add eax, ecx
					inc esi
					jmp atoi_loop
			atoi_done:
			}

			this->port = res;
		}
		else { this->port = DEFAULT_PORT; }

	}

	std::string strPort = std::to_string(this->port);
	const char* port = strPort.c_str();

	WSADATA wsa;
	int iR, iSR = 0;

	iR = WSAStartup(MAKEWORD(2, 2), &wsa);

	if (iR != 0) {
		WSACleanup();
		throw HttpException("ERR::In WSAstartup");
	}

	struct addrinfo* result = NULL, * ptr = NULL, hints;

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_flags = 0x01;
	hints.ai_family = 0x02;
	hints.ai_socktype = 0x01;
	hints.ai_protocol = 0x06;

	iR = getaddrinfo(NULL, port, &hints, &result);
	if (iR != 0) {
		WSACleanup();
		throw HttpException("ERR::In getaddrinfo");
	}

	SOCKET lSock = INVALID_SOCKET;
	lSock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	if (lSock == INVALID_SOCKET) {
		WSACleanup();
		freeaddrinfo(result);
		throw HttpException("ERR::In init listen socket");
	}

	iR = bind(lSock, result->ai_addr, static_cast<int>(result->ai_addrlen));

	if (iR == SOCKET_ERROR) {
		freeaddrinfo(result);
		closesocket(lSock);
		WSACleanup();
		throw HttpException("ERR::In bind socket");
	}

	if (listen(lSock, 0x20) == SOCKET_ERROR) {
		freeaddrinfo(result);
		WSACleanup();
		throw HttpException("ERR::In listen socket");
	}

	std::string msg = std::string("Server started under ip: ") + getIp(*result->ai_addr) + " on port: " + strPort;
	HttpLogger::log(msg, HttpLogger::LOG);

	try {
		HttpListener listener(lSock);
		listener.listen();
	} catch (HttpException& ex) {
		HttpLogger::log(ex.what(), HttpLogger::ERR);
	}

	freeaddrinfo(result);
	WSACleanup();

}

std::string HttpLauncher::getIp(sockaddr& addr) {
	if (addr.sa_family == AF_INET) {
		sockaddr_in* addr_in = reinterpret_cast<struct sockaddr_in*>(&addr);

		char ip[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &(addr_in->sin_addr), ip, INET_ADDRSTRLEN);

		return std::string(ip);
	}

	return "";

}