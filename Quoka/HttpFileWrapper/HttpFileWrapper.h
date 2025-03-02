#pragma once
#ifndef HTTP_FILE_WRAPPER_H
#define HTTP_FILE_WRAPPER_H

#include <string>
#include <fstream>

class HttpFileWrapper {

	public:
		HttpFileWrapper(const std::string& path);

		std::ifstream& getFile();
		std::string getPath();

	private:
		std::ifstream file;
		std::string path;

};

#endif // !HTTP_FILE_WRAPPER_H
