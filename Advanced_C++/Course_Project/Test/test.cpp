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
		std::string name = section_name;
		name.pop_back();
		name.erase(name.begin());
		return name;
	}
	bool Integer(const std::string& value) noexcept {
		int counter = 0;
		for (auto itr = value.begin(); itr != value.end(); ++itr) {
			if (*itr >= '0' && *itr <= '9') {
				++counter;
			}
		}
		if (counter == value.size()) {
			return true;
		} else {
			return false;
		}
	}
	bool Double(const std::string& value) noexcept {
		int counter = 0;
		for (auto itr = value.begin(); itr != value.end(); ++itr) {
			if ((*itr >= '0' && *itr <= '9') || *itr == '.') {
				++counter;
			}
		}
		if (counter == value.size() && value.find('.')) {
			return true;
		} else {
			return false;
		}
	}

	std::variant<int, double, std::string> setTypeOf(const std::string& value) {
		std::variant<int, double, std::string> temp_value;
		if (!value.empty()) {
			if (Integer(value)) {
				temp_value = std::stoi(value);
				//std::cout << std::get<int>(temp_value) << '-' << typeid(std::get<int>(temp_value)).name() << std::endl;
			}
			else if (Double(value)) {
				temp_value = std::stod(value);
				//std::cout << std::get<double>(temp_value) << '-' << typeid(std::get<double>(temp_value)).name() << std::endl;
			}
			else {
				temp_value = value;
				//std::cout << std::get<std::string>(temp_value) << '-' << typeid(std::get<std::string>(temp_value)).name() << std::endl;
			}
		} else {
			temp_value = "";
		}
		return temp_value;
	}
public:
	Parse() = default;

	Parse(std::ifstream& file) {
		if (!file.is_open()) {
			std::cout << "Error: file is unable!" << std::endl;
			std::exit(EXIT_FAILURE);
		} else {
			std::string section;
			while (!file.eof()) {
				std::string line, word;
				std::string variable, value;
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
						}
						if (count(temp_line.begin(), temp_line.end(), '=')) {
							for (int i = 0; i < temp_line.length(); ++i) {
								if (i < temp_line.find('=')) {
									variable += temp_line[i];
								} else if (i > temp_line.find('=')) {
									value += temp_line[i];
								}
							}
						}
					}
					sections[section][variable] = setTypeOf(value);
				}
				if (sections.size() > 1) {
					sections.at(section).erase("");
				}
			}
		}
	}

	template<typename T>
	const T get_value(const std::string& query) const {
		if (!query.empty()) {
			const std::pair<std::string, std::string> command = parceQuery(query);
			const std::string section = command.first;
			const std::string parameter = command.second;
			auto value = std::get<T>(sections.at(section).at(parameter));

			if (!sections.count(section)) {
				throw std::out_of_range("wrong section");
			}
			if (!sections.at(section).count(parameter)) {
				throw std::out_of_range("wrong parameter");
			}

			if (std::holds_alternative<std::string>(sections.at(section).at(parameter))) {
				const std::string temp_value = std::get<std::string>(sections.at(section).at(parameter));
				if (temp_value.empty()) {
					std::cout << "Thrown exception: value at '" << section << '.' << parameter << "' is ";
					throw std::exception("empty");
				}
			}
			
			return value;
		} else {
			throw std::exception("invalid input");
		}
	}

	void print() const noexcept {
		for (const auto& [section, variables] : sections) {
			std::cout << section << std::endl;
			for (const auto& [variable, value] : variables) {
				if (std::holds_alternative<int>(value)) {
					std::cout << variable << '=' << std::get<int>(value);
					std::cout << " (type " << typeid(std::get<int>(value)).name() << ')' << std::endl;
				} else if (std::holds_alternative<double>(value)) {
					std::cout << variable << '=' << std::get<double>(value);
					std::cout << " (type " << typeid(std::get<double>(value)).name() << ')' << std::endl;
				} else {
					std::cout << variable << '=' << std::get<std::string>(value);
					std::cout << " (type " << typeid(std::get<std::string>(value)).name() << ')' << std::endl;
				}
			}
		}
	}

	~Parse() = default;
};

int main(int argc, char** argv) {
	try {
		std::ifstream file("test.ini");
		Parse parcer(file);

		std::cout << std::endl << "TEST METHOD .print():" << std::endl;
		parcer.print();

		std::cout << std::endl;
		std::cout << "REQUESTS:" << std::endl;

		std::string query1{ "Section1.var1" };
		auto value1 = parcer.get_value<double>(query1);
		std::cout << "Section1.var1=" << value1 << std::endl;

		std::string query2{ "Section2.var1" };
		auto value2 = parcer.get_value<int>(query2);
		std::cout << "Section2.var1=" << value2 << std::endl;
		
		std::string query3{ "Section2.var2" };
		auto value3 = parcer.get_value<std::string>(query3);
		std::cout << "Section2.var2=" << value3 << std::endl;

		std::string query4{ "Section4.Vid" };
		auto value4 = parcer.get_value<std::string>(query4);
		std::cout << "Section4.Vid=" << value4 << std::endl;

		std::string query5{ "Section5.Vid" };
		auto value5 = parcer.get_value<std::string>(query5);
		std::cout << "Section5.Vid=" << value5 << std::endl;
	}

	catch (const std::exception& error) {
		std::cerr << error.what() << std::endl;
	}
	return EXIT_SUCCESS;
}