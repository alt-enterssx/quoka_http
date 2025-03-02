#include "./HttpException.h"

HttpException::HttpException(const char* msg) noexcept : msg(msg) {}

const char* HttpException::what() const noexcept { return this->msg; }