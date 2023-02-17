#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& vect) {
	std::for_each(vect.begin(), vect.end(), [&out](int elm){ out << std::setw(2) << elm << ' '; });
	return out;
}

void oddElement_x3(const int& num, std::vector<int>& vect) {
	std::for_each(vect.begin(), vect.end(), [&num](int& elm) {
		if (elm % 2 != 0) {
			elm *= 3;
		}
	});
	return;
}

int main(int argc, char** argv) {
	const auto num = 3;
	std::vector<int> vect = { 4, 7, 9, 14, 12 };

	std::cout << "Initial vector:\t" << vect << std::endl;
	oddElement_x3(num, vect);
	std::cout << "New vector:\t" << vect << std::endl;

	return 0;
}