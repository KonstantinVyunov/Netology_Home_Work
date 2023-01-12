// Time Complexity  - O(n) linar
// Space Complexity - O(n) linar

#include <iostream>
#include <chrono>

static long long signed fibonachi_row[100] = { 0, 1 };

long long signed fibonachi(const int num) {
	if (num == 0) {
		return fibonachi_row[0];
	}
	else if (num == 1) {
		return fibonachi_row[1];
	}
	else if (fibonachi_row[num] != 0) {
		return fibonachi_row[num];
	}
	else {
		fibonachi_row[num] = fibonachi(num - 1) + fibonachi(num - 2);
		return fibonachi_row[num];
	}
}

int main(int argc, char** argv) {
	std::cout << "Enter the number: ";
	int num = 0;
	std::cin >> num;
	std::cout << "(Rapid) The Fibonachi num: ";
	auto start = std::chrono::high_resolution_clock::now();
	std::cout << fibonachi(num);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	std::cout << " (took " << duration.count() << " seconds)" << std::endl;
	return 0;
}