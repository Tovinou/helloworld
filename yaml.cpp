#include <iostream>
#include <fstream>
#include <unordered_map>
#include <variant>
#include <vector>
#include <string>
#include <yaml-cpp/yaml.h>

class YamlParser {
public:
    YamlParser(const std::string& filePath) {
        try {
            YAML::Node config = YAML::LoadFile(filePath);
            loadData(config);
        } catch (const YAML::Exception& e) {
            std::cerr << "YAML Error: " << e.what() << std::endl;
            throw e;
        }
    }

    std::string getString(const std::string& key) const {
        if (data.find(key) != data.end() && std::holds_alternative<std::string>(data.at(key))) {
            return std::get<std::string>(data.at(key));
        }
        return "";
    }

    int getInt(const std::string& key) const {
        if (data.find(key) != data.end() && std::holds_alternative<std::string>(data.at(key))) {
            return std::stoi(std::get<std::string>(data.at(key)));
        }
        return 0;
    }

    bool getBool(const std::string& key) const {
        if (data.find(key) != data.end() && std::holds_alternative<bool>(data.at(key))) {
            return std::get<bool>(data.at(key));
        }
        return false;
    }

    std::vector<std::string> getStringList(const std::string& key) const {
        if (data.find(key) != data.end() && std::holds_alternative<std::vector<std::string>>(data.at(key))) {
            return std::get<std::vector<std::string>>(data.at(key));
        }
        return {};
    }

private:
    std::unordered_map<std::string, std::variant<std::string, std::vector<std::string>, bool>> data;

    void loadData(const YAML::Node& node) {
        for (const auto& pair : node) {
            std::string key = pair.first.as<std::string>();
            if (pair.second.IsScalar()) {
                if (pair.second.Tag() == "tag:yaml.org,2002:bool") {
                    data[key] = pair.second.as<bool>();
                } else {
                    data[key] = pair.second.as<std::string>();
                }
            } else if (pair.second.IsSequence()) {
                std::vector<std::string> list;
                for (const auto& item : pair.second) {
                    list.push_back(item.as<std::string>());
                }
                data[key] = list;
            } else if (pair.second.IsMap()) {
                loadData(pair.second);
            }
        }
    }
};

int main() {
    try {
        YamlParser parser("parser.yaml");

        std::string name = parser.getString("name");
        int age = parser.getInt("age");
        std::vector<std::string> items = parser.getStringList("items");
        bool debug = parser.getBool("settings.debug");
        int timeout = parser.getInt("settings.timeout");

        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Items:" << std::endl;
        for (const auto& item : items) {
            std::cout << "- " << item << std::endl;
        }
        std::cout << "Debug: " << (debug ? "true" : "false") << std::endl;
        std::cout << "Timeout: " << timeout << std::endl;
    } catch (const YAML::Exception& e) {
        std::cerr << "YAML Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
