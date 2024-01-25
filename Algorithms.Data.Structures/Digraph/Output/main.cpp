#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

int main(int argc, char** argv) {
	std::ifstream file("input.txt");
	int vertices_num = 0;
	std::list<std::list<int>> digraph;

	if (!file.is_open()) {
		std::cerr << "Error: Unable file!" << std::endl;
		exit(EXIT_FAILURE);
	} else {
		std::string size, line, box;
		std::getline(file, size);
		vertices_num = stoi(size);
		while (!file.eof()) {
			int edge_counter = 0;
			std::getline(file, line);
			std::list<int> temp;
			std::stringstream ss(line);
			while (std::getline(ss, box, ' ')) {
				++edge_counter;
				if (box == "1") {
					temp.push_back(edge_counter);
				}
			}
			digraph.push_back(temp);
		}
	}

	file.close();

	std::cout << "The digraph output:" << std::endl;
	if (!digraph.empty()) {
		int vertex = 0;
		for (const auto& row : digraph) {
			if (vertex < vertices_num) { ++vertex; }
			std::cout << vertex << ": ";
			if (!row.empty()) {
				for (const auto& elm : row) {
					std::cout << elm << ' ';
				}
			} else {
				std::cout << "no";
			}
			std::cout << std::endl;
		}
	} else {
		std::cout << "The digraph is empty!" << std::endl;
	}
	return EXIT_SUCCESS;
}