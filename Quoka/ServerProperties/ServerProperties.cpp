#include "./ServerProperties.h"

std::map<std::string, std::string> ServerProperties::props;

ServerProperties::ServerProperties() {}

void ServerProperties::setFile(HttpFileWrapper&& wrapper) {

    size_t ind = wrapper.getPath().find_last_of('.');
    if (ind != std::string::npos) {
        std::string ext = wrapper.getPath().substr(ind + 1);
        if (ext != "prop") {
            throw HttpException("This is not propety file");
        }
    }

    if (!wrapper.getFile().is_open()) {
        throw HttpException("In read config file");
    }

    std::string prop;
    while (std::getline(wrapper.getFile(), prop)) {
        size_t delimiter = prop.find(':');
        if (delimiter != std::string::npos) {
            std::string key = prop.substr(0, delimiter);
            std::string value = prop.substr(delimiter + 1);

            key.erase(0, key.find_first_not_of(" \t"));
            key.erase(key.find_last_not_of(" \t") + 1);
            value.erase(0, value.find_first_not_of(" \t"));
            value.erase(value.find_last_not_of(" \t") + 1);

            this->props[key] = value;
        }
    }
}

std::string ServerProperties::getProperty(const std::string& str) {
    auto iter = props.find(str);
    return (iter == props.end()) ? "" : iter->second;
}
