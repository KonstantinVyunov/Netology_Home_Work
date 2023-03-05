#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& i_vect) {
	std::for_each(i_vect.begin(), i_vect.end(), [](const int& elm) {std::cout << elm << ' '; });
	return out;
}

struct Functor {
	bool operator()(int& num) {
		if (num % 3 == 0) {
			return true;
		} else {
			return false;
		}
	}
};

int getSum(std::vector<int>& i_vect, Functor& functor) {
	int sum = 0;
	for ( auto& elm : i_vect) {
		if (functor(elm)) {
			sum += elm;
		}
	}
	// IS IT POSSIBLE TO USE std::accumulate() HERE?
	// Gives an error because of functor that i can't interpret.
	// return std::accumulate(i_vect.begin(), i_vect.end(), 0, functor);
	return sum;
}

int getCount(std::vector<int>& i_vect, Functor& functor) {
	return std::count_if(i_vect.begin(), i_vect.end(), functor);
}

int main(int argc, char** argv) {
	Functor functor{};
	std::vector<int> i_vect = { 4, 1, 3, 6, 25, 54 };
	
	std::cout << "[IN]: " << i_vect << std::endl;
	std::cout << "[OUT]: getSum() = " << getSum(i_vect, functor) << std::endl;
	std::cout << "[OUT]: getCount() = " << getCount(i_vect, functor) << std::endl;

	return 0;
}