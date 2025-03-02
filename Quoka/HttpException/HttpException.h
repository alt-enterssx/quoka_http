#pragma once
#ifndef HTTP_EXCEPTION_H
#define HTTP_EXCEPTION_H

#include <exception>

class HttpException : public std::exception { 

	public:
		HttpException(const char* msg) noexcept;
		const char* what() const noexcept override;

	private:
		const char* msg;

};

#endif // HTTP_EXCEPTION_H
