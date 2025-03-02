#include "./HtmlReader.h"

std::string HtmlReader::readFile(HttpFileWrapper&& wrapper) {
	
	size_t ind = wrapper.getPath().find_last_of('.');
	if (ind != std::string::npos) {
		std::string ext = wrapper.getPath().substr(ind + 1);
		if (ext != "html") {
			throw HttpException("This is not html file");
		}
	}

	std::string body = "";
	std::string line = "";
	
	while (std::getline(wrapper.getFile(), line)) {
		body += line;
		line.clear();
	}

	return body;
}
