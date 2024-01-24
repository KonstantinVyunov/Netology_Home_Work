#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void reachToFile(std::ifstream& file) {
	if (!file.is_open()) {
		throw std::exception("The file is not available!");
	}
}

struct Vertex {
	int num;
	bool visited;
	std::vector<int> edges;
};

class Graph {
private:
	int vertices_quantity = 0;
	std::vector<Vertex> matrix;
public:
	Graph() = default;
	Graph(Graph& other) = delete;
	Graph& operator=(Graph& other) = delete;

	Graph(std::ifstream& file) {
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

	void dfs(int vertex = 0) {
		if (vertex < 0 || vertex > this->vertices_quantity) {
			throw std::exception("Vertex is out of range!");
		} else {
			for (; vertex < this->vertices_quantity; ++vertex) {
				if (matrix[vertex].visited != true) {
					std::cout << matrix[vertex].num << ' ';
					matrix[vertex].visited = true;
					for (int edge = 0; edge < matrix[vertex].edges.size(); ++edge) {
						const int next_vertex_index = matrix[vertex].edges[edge] - 1;
						if (matrix[next_vertex_index].visited != true) {
							dfs(next_vertex_index);
						}
					}
				}
			}
		}
	}

	void printMatrix() const noexcept {
		for (const auto& vertex : matrix) {
			std::cout << "vertex " << vertex.num << ": ";
			for (const auto& edge : vertex.edges) {
				std::cout << edge << ' ';
			}
			std::cout << std::endl;
		}
	}

	~Graph() = default;
};

int main(int argc, char** argv) {
	std::ifstream file("input.txt");
	try {
		reachToFile(file);
	}
	catch (const std::exception& error) {
		std::cerr << "Error: " << error.what() << std::endl;
		return EXIT_FAILURE;
	}

	Graph graph(file);
	std::cout << "Matrix:\n";
	graph.printMatrix();

	std::cout << "\nEnter the initial vertex: ";
	int start = 0;


	try {
		std::cin >> start;
		std::cout << "\nPath: ";
		graph.dfs(start - 1);
	}
	catch (const std::exception& error) {
		std::cerr << "doesn't exists!\nError: " << error.what() << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}