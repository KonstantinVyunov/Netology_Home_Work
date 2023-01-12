// Time Complexity  - O(2n) exponential
// Space Complexity - O(n) linar

#include <iostream>
#include <chrono>

long long signed fibonachi(int num) {
	if (num == 0) {
		return 0;
	} else if (num == 1 || num == -1) {
		return 1;
	} else if (num > 0) {
		return (fibonachi(num - 1) + fibonachi(num - 2));
	} else {
		return (fibonachi(num + 2) - fibonachi(num + 1));
	}
}

int main(int argc, char** argv) {
	std::cout << "Enter the number: ";
	int num = 0;
	std::cin >> num;
	std::cout << "(Common) The Fibonachi num: ";
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << fibonachi(num);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	std::cout << " (took " << duration.count() << " seconds)" << std::endl;
	return 0;
}