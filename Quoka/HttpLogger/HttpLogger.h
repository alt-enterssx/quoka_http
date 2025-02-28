#pragma once
#ifndef HTTP_LOGGER_H
#define HTTP_LOGGER_H

#include <string>
#include <iostream>

class HttpLogger {

	public:
		enum LoggerType {
			LOG = 0x0,
			ERR = 0x1,
			UNKWOWN = 0x2
		};

		static void log(const std::string& logStr, LoggerType type) noexcept;

};

#endif // !HTTP_LOGGER_H




