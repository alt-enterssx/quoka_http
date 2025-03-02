#pragma once
#ifndef HTML_READER_H
#define HTML_READER_H

#include "../HttpException/HttpException.h"
#include "../HttpFileWrapper/HttpFileWrapper.h"

#include <fstream>
#include <string>

class HtmlReader {

	public:
		static std::string readFile(HttpFileWrapper&& wrapper);

};

#endif // !HTTP_READER_H
