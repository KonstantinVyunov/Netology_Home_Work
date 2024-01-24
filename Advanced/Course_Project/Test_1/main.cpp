#include <algorithm>
#include <exception>
#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class Parser {
private:
	std::map<std::string, std::map<std::string, std::string>> ini_file;
protected:
	void isAvailable(std::ifstream& file) {
		if (!file.is_open()) {
			std::cout << "Error: file is unable!" << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	const std::string removeBrackets(std::string& section_name) {
		std::string name = section_name;
		name.pop_back();
		name.erase(name.begin());
		return name;
	}
	const std::pair<std::string, std::string> splitLine(const std::string& query, const char chr) const noexcept {
		std::pair<std::string, std::string> command;
		for (int i = 0; i < query.length(); ++i) {
			if (i < query.find(chr)) {
				command.first += query[i];
			}
			else if (i > query.find(chr)) {
				command.second += query[i];
			}
		}
		return command;
	}
	std::string checkQueryForSecVar(const std::string& line) {
		std::pair<std::string, std::string> section_variable = splitLine(line, '.');
		std::string section = section_variable.first;
		std::string variable = section_variable.second;
		std::string str_value;

		if (!ini_file.count(section)) {
			std::cout << "wrong section" << std::endl;
			exit(EXIT_FAILURE);
		}
		else {
			if (!ini_file.at(section).count(variable)) {
				std::cout << "wrong variable" << std::endl;
				exit(EXIT_FAILURE);
			}
			else {
				str_value = ini_file.at(section).at(variable);
			}
		}
		return str_value;
	}

	template<typename T>
	T conversionTo(const std::string& str_value) {
		std::cout << "unknown conversion" << std::endl;
		exit(EXIT_FAILURE);
	}
	template<>
	double conversionTo(const std::string& str_value) {
		int counter = 0;
		for (auto itr = str_value.begin(); itr != str_value.end(); ++itr) {
			if ((*itr >= '0' && *itr <= '9') || *itr == '.') {
				++counter;
			}
		}
		if (counter == str_value.size() && str_value.find('.')) {
			return std::stod(str_value);
		} else {
			std::cout << "(Error: value is not convertible into double type or converts incorrectly!)" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	template<>
	int conversionTo(const std::string& str_value) {
		int counter = 0;
		for (auto itr = str_value.begin(); itr != str_value.end(); ++itr) {
			if (*itr >= '0' && *itr <= '9') {
				++counter;
			}
		}
		if (counter == str_value.size()) {
			return std::stoi(str_value);
		}
		else {
			std::cout << "(Error: value is not convertible into integer type or converts incorrectly!)" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	
public:
	Parser(std::ifstream& file) {
		isAvailable(file);
		std::string section;
		while (!file.eof()) {
			std::string line;
			std::getline(file, line);
			if (!line.empty()) {
				std::stringstream ss(line);
				std::string word;
				std::string temp_line;
				while (std::getline(ss, word, ' ')) {

					// убираем лишние символы
					if (word == ";") { break; }
					if (word.empty()) { continue; }
					if (word.front() == '\t' || word.back() == '\t') {
						word.erase(remove(word.begin(), word.end(), '\t'), word.end());
					}
					temp_line += word;
				}
				// распознаём и вычленяем section, variable и value
				std::string variable, value;
				if (!temp_line.empty()) {
					if (temp_line.front() == '[' && temp_line.back() == ']') {
						section = removeBrackets(temp_line);
					} else if (count(temp_line.begin(), temp_line.end(), '=')) {
						std::pair<std::string, std::string> variable_value = splitLine(temp_line, '=');
						variable = variable_value.first;
						value = variable_value.second;
					}
				}
				ini_file[section][variable] = value;
			}
			// убраем пустые строки, при наличии 
			if (ini_file.size() > 1) {
				ini_file.at(section).erase("");
			}
		}
	}

	template<typename T>
	T get_value(const std::string& query) {
		std::cout << "not implemented convertion" << std::endl;
		exit(EXIT_FAILURE);
	}

	template<>
	std::string get_value(const std::string& query) {
		std::string value;
		if (query.empty()) {
			std::cout << "empty input" << std::endl;
			exit(EXIT_FAILURE);
		} else {
			std::string str_value = checkQueryForSecVar(query);
			if (str_value.empty()) { value = "(empty value)"; }
			else { value = str_value; }
		}
		return value;
	}

	template<>
	double get_value(const std::string& query) {
		double value = 0;
		if (query.empty()) {
			std::cout << "empty input" << std::endl;
			exit(EXIT_FAILURE);
		} else {
			std::string str_value = checkQueryForSecVar(query);
			value = conversionTo<double>(str_value);
		}
		return value;
	}

	template<>
	int get_value(const std::string& query) {
		int value = 0;
		if (query.empty()) {
			std::cout << "empty input" << std::endl;
			exit(EXIT_FAILURE);
		} else {
			std::string str_value = checkQueryForSecVar(query);
			value = conversionTo<int>(str_value);
		}
		return value;
	}

	void print() const noexcept {
		for (const auto& [section, block] : ini_file) {
			std::cout << section << std::endl;
			for (const auto& [key, value] : block) {
				std::cout << key << '=' << value << std::endl;
			}
		}
	}

	~Parser() {}
};

int main(int argc, char** argv) {
	std::ifstream file("test.ini");
	Parser parser(file);
	//parser.print();
	std::cout << "Section1\nvar1=";
	auto double_value = parser.get_value<double>("Section1.var1");
	std::cout << double_value << std::endl;

	std::cout << "Section2\nvar1=";
	auto int_value = parser.get_value<int>("Section2.var1");
	std::cout << int_value << std::endl;

	std::cout << "Section2\nvar2=";
	auto string_value = parser.get_value<std::string>("Section2.var2");
	std::cout << string_value << std::endl;

	std::cout << "Section4\nVid=";
	auto empty_value = parser.get_value<std::string>("Section4.Vid");
	std::cout << empty_value << std::endl;

	return EXIT_SUCCESS;
}