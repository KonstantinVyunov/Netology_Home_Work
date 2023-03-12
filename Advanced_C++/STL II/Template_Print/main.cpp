#include <iostream>
#include <vector>
#include <list>
#include <set>

template<class T>
void print_container(const T& container) {
	for (auto itr = container.begin(); itr != container.end(); ++itr) {
		std::cout << *itr << ' ';
	}
}

int main(int argc, char** argv) {
	std::set<std::string> test_set = { "one", "two", "three", "four" };
	std::cout << "set:\t";
	print_container(test_set); // four one three two. помните почему такой порядок? :)
	std::cout << std::endl;

	std::list<std::string> test_list = { "one", "two", "three", "four" };
	std::cout << "list:\t";
	print_container(test_list); // one, two, three, four
	std::cout << std::endl;

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	std::cout << "vector: ";
	print_container(test_vector); // one, two, three, four
	std::cout << std::endl;

	return EXIT_SUCCESS;
}