#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vect) {
	std::for_each(vect.begin(), vect.end(), [&out](const int& elm) { out << elm << ' '; });
	return out;
}

template <typename T>
T exponent(T& num) {
	return (num = pow(num, 2));
}

template <>
std::vector<int> exponent(std::vector<int>& i_vect) {
	for (auto& elm : i_vect) {
		elm = pow(elm, 2);
	}
	return i_vect;
}

int main(int argc, char** argv) {
	int num = 4;
	std::vector<int> i_vect = {-1, 4, 8};
	
	std::cout << "[IN]: " << num << std::endl;
	std::cout << "[OUT]: " << exponent<int>(num) << std::endl;
	
	std::cout << "[IN]: " << i_vect << std::endl;
	std::cout << "[OUT]: " << exponent<std::vector<int>>(i_vect) << std::endl;

	return 0;
}