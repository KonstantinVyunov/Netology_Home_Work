#include <algorithm>
#include <iostream>
#include <vector>

template<typename G>
void print(const std::vector<G>& vect) {
	for (auto itr = vect.begin(); itr != vect.end(); ++itr) {
		std::cout << *itr << ' ';
	}
}

template<typename T>
void my_unique(std::vector<T>& vect) {
	std::sort(vect.begin(), vect.end());
	auto ptr_end = std::unique(vect.begin(), vect.end());
	vect.erase(ptr_end, vect.end());
}

int main(int argc, char** argv) {
	//std::vector<int> vect = { 1, 1, 2, 5, 6, 1, 2, 4 };
	std::vector<char> vect = { 'a', 'b', 'a', 'c', 'd', 'e', 'c', 'a' };

	std::cout << " [IN]: ";
	print(vect);

	my_unique(vect);
	std::cout << std::endl;

	std::cout << "[OUT]: ";
	print(vect);

	return EXIT_SUCCESS;
}