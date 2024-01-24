#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

bool comparator(std::pair<char, int>& lhs, std::pair<char, int>& rhs) {
	if (lhs.second == rhs.second) {
		return lhs.first < rhs.first;
	} else {
		return (lhs.second > rhs.second);
	}
}

int countChr(const int& i, const std::string& line) {
	int counter = 0;
	const size_t l = line.length();
	for (int j = i + 1; j < l; ++j) {
		if (line[i] == line[j]) {
			++counter;
		}
	}
	return counter;
}

std::vector<std::pair<char, int>> parceLine(const std::string& line) {
	std::vector<std::pair<char, int>> chars;
	for (int i = 0; i < line.length(); ++i) {
		int counter = 1;
		if (chars.empty()) {
			counter += countChr(i, line);
			chars.push_back({line[i], counter});
		} else {
			bool coincedence = false;
			for (const auto& [chr, cntr] : chars) {
				if (line[i] == chr) {
					coincedence = true;
					break;
				}
			} if (coincedence == false) {
				counter += countChr(i, line);
				chars.push_back({ line[i], counter });
			}
		}
	}
	return chars;
}



int main(int argc, char** argv) {
	std::string line = {"Hello world!!"};

	std::cout << "[IN]: " << line << std::endl;
	std::vector<std::pair<char, int>> chars = parceLine(line);
	std::sort(chars.begin(), chars.end(), comparator);

	std::cout << "[OUT]:" << std::endl;
	for (auto& [chr, counter] : chars) {
		std::cout << chr << " [" << (int)chr << "]\t" << " - " << counter << std::endl;
	}

	return 0;
}