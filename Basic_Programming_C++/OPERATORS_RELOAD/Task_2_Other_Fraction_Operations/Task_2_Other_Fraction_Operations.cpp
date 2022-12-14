#include <iostream>

class Fraction {
private:
	int numerator = 0, denominator = 0;

public:
	Fraction(int numerator_, int denominator_) : numerator(numerator_), denominator(denominator_) {}

	friend std::ostream& operator<< (std::ostream& output, Fraction& fraction_);

	int getNumerator() const {
		return this->numerator;
	}

	int getDenominator() const {
		return this->denominator;
	}

	bool operator== (const Fraction& r_value) {
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

	const Fraction fractionReduction(Fraction& fraction) {
		if (fraction.getNumerator() % 2 == 0 && fraction.getDenominator() % 2 == 0) {
			while (fraction.getNumerator() % 2 == 0 && fraction.getDenominator() % 2 == 0) {
				fraction = { fraction.getNumerator() / 2, fraction.getDenominator() / 2 };
			}
		}
		else if (fraction.getNumerator() % 3 == 0 && fraction.getDenominator() % 3 == 0) {
			while (fraction.getNumerator() % 3 == 0 && fraction.getDenominator() % 3 == 0) {
				fraction = { fraction.getNumerator() / 3, fraction.getDenominator() / 3 };
			}
		}
		return fraction;
	}

	const Fraction& operator+ (const Fraction& r_value) {
		Fraction sum = { (this->numerator * r_value.denominator
			+ r_value.numerator * this->denominator),
			(this->denominator * r_value.denominator) };
		return fractionReduction(sum);
	}

	const Fraction& operator- (const Fraction& r_value) {
		Fraction sub = { (this->numerator * r_value.denominator
			- r_value.numerator * this->denominator),
			(this->denominator * r_value.denominator)
		};
		return fractionReduction(sub);
	}

	friend const Fraction& operator* (const Fraction& l_value, const Fraction& r_value);

	const Fraction& operator/ (const Fraction& r_value) {
		Fraction div = { this->numerator * r_value.denominator,
			this->denominator * r_value.numerator };
		return fractionReduction(div);
	}

	const Fraction operator++ () {
		return {this->numerator += this->denominator, this->denominator};
	}

	const Fraction operator-- () {
		return { this->numerator -= this->denominator, this->denominator };
	}

	const Fraction operator++ (int) {
		Fraction temp = *this;
		++(*this);
		return temp;
	}

	Fraction operator-- (int) {
		Fraction temp = *this;
		--(*this);
		return temp;
	}

	~Fraction() = default;
};

const Fraction& operator* (const Fraction& l_value, const Fraction& r_value) {
	Fraction mult = { (l_value.numerator * r_value.numerator),
		(l_value.denominator * r_value.denominator) };
	return mult.fractionReduction(mult);
}

std::ostream& operator<< (std::ostream& output, Fraction& fraction) {
	output << fraction.numerator << '/' << fraction.denominator;
	return output;
}

Fraction& setFraction() {
	int numerator = NULL, denominator = NULL;
	std::cout << "Numerator: ";
	std::cin >> numerator;
	std::cout << "Denominator: ";
	std::cin >> denominator;
	Fraction fraction = { numerator, denominator };
	return fraction;
}

int main(int argc, char** argv) {
	std::cout << "Enter the first fraction.\n";
	Fraction f1 = setFraction();
	std::cout << "Enter the second fraction.\n";
	Fraction f2 = setFraction();
	Fraction result = { NULL, NULL };
	std::cout << std::endl;
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	std::cout << std::endl;
	std::cout << f1 << " + " << f2 << " = " << (result = (f1 + f2)) << std::endl;
	std::cout << f1 << " - " << f2 << " = " << (result = (f1 - f2)) << std::endl;
	std::cout << f1 << " * " << f2 << " = " << (result = (f1 * f2)) << std::endl;
	std::cout << f1 << " / " << f2 << " = " << (result = (f1 / f2)) << std::endl;
	std::cout << std::endl;

	std::cout << "++" << f1 << " * " << f2 << " = ";
	std::cout << (result = (++f1) * f2) << std::endl;
	std::cout << "Fraction value 1 = " << (f1) << std::endl;

	std::cout << f1 << "-- * " << f2 << " = ";
	std::cout << (result = (f1--) * f2) << std::endl;
	std::cout << "Fraction value 1 = " << (f1) << std::endl;

	return 0;
}