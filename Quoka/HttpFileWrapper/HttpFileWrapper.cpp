#include "./HttpFileWrapper.h"

HttpFileWrapper::HttpFileWrapper(const std::string& path) {
	this->file = std::ifstream(path);
	this->path = path;
}

std::ifstream& HttpFileWrapper::getFile() { return this->file; }

std::string HttpFileWrapper::getPath() { return this->path; }
