#pragma once
#ifndef SERVER_PROPERTIES_H
#define SERVER_PROPERTIES_H

#include "../HttpException/HttpException.h"

#include <fstream>
#include <string>
#include <map>
#include <vector>

class ServerProperties {

	public:
		ServerProperties();

		void setFile(std::ifstream& fileR);
		static std::string getProperty(const std::string& str);

	private:
		static std::map<std::string, std::string> props;

};

#endif // !SERVER_PROPERTIES_H
