#include <iostream>

class Fraction {
public:
	int numerator = 0, denominator = 0;

public:
	Fraction(int numerator_, int denominator_) : numerator(numerator_), denominator(denominator_) {}

	bool operator== (const Fraction &r_value) {
		return ((this->numerator == r_value.numerator)
			&& (this->denominator == r_value.denominator) ? true : false);
	}
	bool operator!= (const Fraction& r_value) {
		return !(*this == r_value);
	}
	bool operator< (const Fraction& r_value) {
		return (((this->numerator / this->denominator) < (r_value.numerator / r_value.denominator))
			? true : false);
	}

	bool operator> (const Fraction& r_value) {
		return !(*this <= r_value);
	}

	bool operator<= (const Fraction& r_value) {
		return (((this->numerator / this->denominator) <= (r_value.numerator / r_value.denominator))
			? true : false);
	}

	bool operator>= (const Fraction& r_value) {
		return !(*this < r_value);
	}
};

int main(int argc, char** argv) {

	Fraction f1(4, 3);
	Fraction f2(6, 11);
	
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	return 0;
}