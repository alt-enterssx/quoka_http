#include "./HttpLogger.h"

void HttpLogger::log(const std::string& logStr, HttpLogger::LoggerType type) noexcept {
	switch (type) {
		case HttpLogger::LOG:
			std::cout << "SERVER::" << logStr << "\n";
			break;
		case HttpLogger::ERR:
			std::cout << "ERROR::" << logStr << "\n";
			break;
		case HttpLogger::UNKWOWN:
			break;
		default:
			break;
	}
}
