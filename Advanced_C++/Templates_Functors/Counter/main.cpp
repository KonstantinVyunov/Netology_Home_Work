#include <algorithm>
#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& out, const std::vector<int>& i_vect) {
	std::for_each(i_vect.begin(), i_vect.end(), [](const int& elm) {std::cout << elm << ' '; });
	return out;
}

class Functor {
private:
	int sum = 0;
	int counter = 0;
public:
	void operator()(const int& num) {
		if (num % 3 == 0) {
			sum += num;
			++counter;
		}
	}
	int getSum() const { return sum; }
	int getCount() const { return counter; }
};

int main(int argc, char** argv) {
	Functor functor;
	std::vector<int> i_vect = { 4, 1, 3, 6, 25, 54 };

	std::for_each(i_vect.begin(), i_vect.end(), [&functor](const int& elm) { functor(elm); });

	std::cout << "[IN]: " << i_vect << std::endl;
	std::cout << "[OUT]: getSum() = " << functor.getSum() << std::endl;
	std::cout << "[OUT]: getCount() = " << functor.getCount() << std::endl;

	return 0;
}