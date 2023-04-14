#include <algorithm>
#include <exception>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <variant>
#include <string>
#include <utility>
#include <map>

class Parse {
private:
	std::map<std::string, std::map<std::string, std::variant<int, double, std::string>>> sections;
protected:
	const std::pair<std::string, std::string> parceQuery(const std::string& query) const noexcept {
		std::pair<std::string, std::string> command;
		for (int i = 0; i < query.length(); ++i) {
			if (i < query.find('.')) {
				command.first += query[i];
			} else if (i > query.find('.')) {
				command.second += query[i];
			}
		}
		return command;
	}
	const std::string removeBrackets(std::string& section_name) {
		section_name.pop_back();
		section_name.erase(section_name.begin());
		return section_name;
	}

public:
	Parse() = default;

	Parse(std::ifstream& file) {
		if (!file.is_open()) {
			std::cout << "Error: file is unable!" << std::endl;
			std::exit(EXIT_FAILURE);
		} else {
			while (!file.eof()) {
				std::string line, word;
				std::string section, variable, value;
				std::getline(file, line);
				if (!line.empty()) {
					std::string temp_line;
					std::stringstream ss(line);
					while (std::getline(ss, word, ' ')) {
						if (word == ";") { break; }
						if (word.empty()) { continue; }
						if (word.front() == '\t' || word.back() == '\t') {
							word.erase(remove(word.begin(), word.end(), '\t'), word.end());
						}
						temp_line += word;
					}

					if (!temp_line.empty()) {
						if (temp_line.front() == '[' && temp_line.back() == ']') {
							section = removeBrackets(temp_line);
							std::cout << section << std::endl; // <---
						}
						if (count(temp_line.begin(), temp_line.end(), '=')) {
							for (int i = 0; i < temp_line.length(); ++i) {
								if (i < temp_line.find('=')) {
									variable += temp_line[i];
								} else if (i > temp_line.find('=')) {
									value += temp_line[i];
								}
							}
							std::cout << variable << '=' << value << std::endl; // <---
						}
						sections[section][variable] = value;
					}
				}
			}
		}
		//sections["Section2"]["var2"] = "first";
		//sections["Section1"]["var1"] = 5.1;
	}

	template<typename T>
	const T get_value(const std::string& query) const {
		if (!query.empty()) {
			const std::pair<std::string, std::string> command = parceQuery(query);
			const std::string section = command.first;
			const std::string parameter = command.second;
			return std::get<T>(sections.at(section).at(parameter));
		} else {
			throw std::exception("invalid input");
		}
	}

	void print() const noexcept {
		for (const auto& [section, variable] : sections) {
			std::cout << section << std::endl;
			for (const auto& [var, val] : variable) {
				std::cout << var << '=' << std::get<std::string>(val) << std::endl;
			}
		}
	}

	~Parse() = default;
};

int main(int argc, char** argv) {
	std::ifstream file("test.ini");
	Parse parcer(file);

	std::string query1{ "Section1.var2" };
	std::string query2{ "Section2.var2" };
	
	//auto value1 = parcer.get_value<std::string>(query1);
	//auto value2 = parcer.get_value<double>(query2);

	//std::cout << value1 << std::endl;
	//std::cout << value2 << std::endl;

	//parcer.print();

	return EXIT_SUCCESS;
}