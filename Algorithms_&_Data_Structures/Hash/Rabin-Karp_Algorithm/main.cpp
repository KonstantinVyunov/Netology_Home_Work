#include <iostream>
#include <string>
#include <cmath>

uint64_t stringHash(const std::string& word) {
	const int p = 137;
	uint64_t hash = 0;
	if (!word.empty()) {
		size_t range = word.size();
		for (size_t i = 0; i < range; ++i) {
			hash += (static_cast<uint64_t>(pow(p, i)) * word[i]);
		}
	} else {
		std::cout << "Empty input!";
	}
	return hash;
}

size_t findSubstringLightRabinKarp(const std::string& line, const std::string& word) {
	size_t index = 0;
	int module = 1'000;

	const uint64_t word_hash = (stringHash(word) % module);
	std::cout << "Word \"" << word << "\" hash: " << word_hash << std::endl; // <---
	uint64_t subline_hash = 0;

	const size_t word_range = word.size();
	size_t line_range = line.size();
	
	for (index = 0; index < (line_range - word_range + 1); ++index) {
		if (index == 0) {
			std::string subline;
			for (size_t i = index; i < word_range; ++i) {
				subline += line[i];
			}
			subline_hash = (stringHash(subline) % module);
			std::cout << line[index] << " Subline (" << subline << ") hash: " << subline_hash << std::endl; // <---
		} else {
			char chr_sub = line[index - 1];
			char chr_add = line[index + word_range - 1];

			char sub_chr = line[index - 1];
			char add_chr = line[index + word_range - 1];
			subline_hash = (subline_hash - sub_chr + add_chr);	// <---- HELP NEEDED!

			std::cout << line[index] << " Subline (sub " << chr_sub << ", add " << chr_add << ") hash: " << subline_hash % module << std::endl; // <---
		}
		if (word_hash != subline_hash) {
			continue;
		} else {
			for (int j = 0; j < word_range; ++j) {
				if (line[index+j != word[j]]) {
					continue;
				}
			}
			return index;
		}
	}
	return index;
}

int main(int argc, char** argv) {

	std::cout << "Enter the line where to search: ";
	std::string line = { "hellohellomydearfriend" };

	std::string word = {};
	std::cin >> line;
	
	do {
		std::cout << "Enter the word to search: ";
		std::cin >> word;
		std::cout << findSubstringLightRabinKarp(line, word) << std::endl;
	} while (word != "exit");

	return EXIT_SUCCESS;
}