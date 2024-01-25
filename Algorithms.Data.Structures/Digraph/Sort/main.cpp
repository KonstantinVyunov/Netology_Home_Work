#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list> 

class Digraph {
private:
	struct Vertex {
		int num;
		bool visited;
		std::vector<int> edges;
	};
	int vertices_quantity = 0;
	std::vector<Vertex> matrix;
	std::list<int> path;
public:
	Digraph() = default;
	Digraph(Digraph& other) = delete;
	Digraph& operator=(Digraph& other) = delete;

	Digraph(std::ifstream& file) {
		if (!file.is_open()) {
			std::cerr << "Error: The file is not available!" << std::endl;
			exit(EXIT_FAILURE);
		}
		std::string size;
		std::getline(file, size);
		this->vertices_quantity = std::stoi(size);
		int i = 0;
		while (!file.eof()) {
			std::string line, box;
			std::getline(file, line);
			std::stringstream ss(line);
			std::vector<int> edges;
			int edge_counter = 0;
			while (std::getline(ss, box, ' ')) {
				++edge_counter;
				if (box == "1") {
					edges.push_back(edge_counter);
				}
			}
			this->matrix.push_back({ ++i, false, edges });
		}
	};

	void dfs(int vertex) {
		if (vertex < 0 || vertex >= this->vertices_quantity) {
			std::cerr << "doesn't exist.\nVertex is out of range!" << std::endl;
			exit(EXIT_FAILURE);
		} else {
			for (; vertex < this->vertices_quantity; ++vertex) {
				if (matrix[vertex].visited != true) {
					matrix[vertex].visited = true;
					for (int edge = 0; edge < matrix[vertex].edges.size(); ++edge) {
						const int next_vertex_index = matrix[vertex].edges[edge] - 1;
						if (matrix[next_vertex_index].visited != true) {
							dfs(next_vertex_index);
						}
					}
					path.push_front(vertex + 1);
				}
			}
		}
	}

	void printMatrix() const noexcept {
		for (const auto& vertex : matrix) {
			std::cout << "vertex " << vertex.num << ": ";
			if (!vertex.edges.empty()) {
				for (const auto& edge : vertex.edges) {
					std::cout << edge << ' ';
				}
			} else {
				std::cout << '-';
			}
			std::cout << std::endl;
		}
	}

	void printPath() const noexcept {
		if (!this->path.empty()) {
			for (auto itr = this->path.begin(); itr != this->path.end(); ++itr) {
				std::cout << *itr << ' ';
			}
		} else {
			std::cerr << "path is empty!" << std::endl;
		}
	}

	~Digraph() = default;
};

const int setInitialVertex(int start = 0) {
	std::cin >> start;
	return (start - 1);
}

int main(int argc, char** argv) {
	std::ifstream file("input.txt");

	Digraph digraph(file);
	std::cout << "Matrix:\n";
	digraph.printMatrix();

	std::cout << "\nEnter the initial vertex: ";
	const int start = setInitialVertex();

	std::cout << "\nPath: ";
	digraph.dfs(start);
	digraph.printPath();

	std::cout << std::endl;
	return EXIT_SUCCESS;
}