#include "./HttpListener.h"

HttpListener::HttpListener(SOCKET& lSock) {
	if (lSock == INVALID_SOCKET) {
		throw HttpException("Listen socket is invalid");
	}

	this->lSock = lSock;
}

HttpListener::~HttpListener() { this->close(); };

void HttpListener::listen() {
	 
	if (this->lSock == INVALID_SOCKET) {
		throw HttpException("Listen socket is invalid");
	}

	ServerProperties prop;

	int iR, iSR = 0;

	int maxBuf;
	char* recvBuf;

	if (prop.getProperty(std::string("default-buffer")) != "") { maxBuf = stoi(prop.getProperty(std::string("default-buffer"))); }
	else { maxBuf = DEFAULT_BUFFER; }

	recvBuf = new char[maxBuf];

	try {
		while (this->worked) {

			SOCKET cSock = INVALID_SOCKET;
			cSock = accept(lSock, NULL, NULL);

			if (cSock == INVALID_SOCKET) {
				WSACleanup();
				closesocket(lSock);
				throw HttpException("In init client socket");
			}

			iR = recv(cSock, recvBuf, maxBuf, 0);
			if (iR > 0) {
				if (iR < maxBuf) {
					recvBuf[iR] = '\0';
				}
				std::string recv = std::string(recvBuf, iR + 1);
				std::cout << recv + '\n';

				try {
					HttpRequest::Request req = HttpRequest::parseRequest(recv);
					HttpRouter router;

					router.route(req, cSock);
				} catch (HttpException& ex) {
					HttpLogger::log(ex.what(), HttpLogger::ERR);
				}
			}
			else if (iR == 0) {
				std::cout << "Connection closed\n";
			}
			else {
				WSACleanup();
				closesocket(cSock);
				throw HttpException("In read recv");
			}

		}
	} catch (HttpException& ex) {
		HttpLogger::log(ex.what(), HttpLogger::LoggerType::ERR);
	}

	delete[] recvBuf;
	WSACleanup();
	closesocket(this->lSock);

}

void HttpListener::close() {
	this->worked = 0x0;
}
