#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>

class bigInteger {
private:
	std::vector<int> vect{};
	int size_ = 0;
public:
	bigInteger() = default;
	bigInteger(const std::string& input) {
		if (!input.empty()) {
			size_ = input.size();
			for (int i = (input.size() - 1); i >= 0; --i) {
				vect.push_back(std::stoi(std::string{input[i]}));
			}
		} else {
			throw std::exception("Passed empty row!");
		}
	}

	bigInteger(bigInteger&& other) noexcept
		: vect(std::exchange(other.vect, {}))
	{}

	bigInteger& operator=(bigInteger&& other) noexcept {
		std::swap(vect, other.vect);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const bigInteger& figure);
	friend bigInteger operator+(const bigInteger& one, const bigInteger& two);
	friend bigInteger operator*(const bigInteger& one, const int num);

	~bigInteger() = default;
};

std::ostream& operator<<(std::ostream& out, const bigInteger& figure) {
	std::for_each(figure.vect.begin(), figure.vect.end(),
		[&out](int elm) {
			out << elm;
		});
	return out;
}

bigInteger operator+(const bigInteger& one, const bigInteger& two) {
	bigInteger temp;
	if (one.size_ >= two.size_) {
		int rest = 0;
		temp.size_ = one.size_;
		for (size_t i = 0; i < one.size_; ++i) {
			if (i < two.size_) {
				int value = one.vect[i] + two.vect[i] + rest;
				if (i == (temp.size_ - 1) && value >= 10) {
					temp.vect.push_back(value % 10);
					temp.vect.push_back(value / 10);
				} else if (value >= 10) {
					temp.vect.push_back(value % 10);
					rest = 1;
				} else {
					temp.vect.push_back(value);
					rest = 0;
				}
			} else {
				temp.vect.push_back(one.vect[i]);
			}
		}
	} else {
		int rest = 0;
		temp.size_ = two.size_;
		for (size_t j = 0; j < two.size_; ++j) {
			if (j < one.size_) {
				int value = one.vect[j] + two.vect[j] + rest;
				if (j == (temp.size_ - 1) && value >= 10) {
					temp.vect.push_back(value % 10);
					temp.vect.push_back(value / 10);
				} else if (value >= 10) {
					temp.vect.push_back(value % 10);
					rest = 1;
				} else {
					temp.vect.push_back(value);
					rest = 0;
				}
			} else {
				temp.vect.push_back(two.vect[j]);
			}
		}
	}
	std::reverse(temp.vect.begin(), temp.vect.end());
	return temp;
}

bigInteger operator*(const bigInteger& one, const int num) {
	bigInteger temp{};
	int length = one.vect.size();
	int rest = 0;
	for (int i = 0; i < length; ++i) {
		int value = one.vect[i] * num + rest;
		if (i == length - 1 && value >= 10) {
			temp.vect.push_back(value % 10);
			temp.vect.push_back(value / 10);
		} else if (value >= 10) {
			temp.vect.push_back(value % 10);
			rest = value / 10;
		} else {
			temp.vect.push_back(value);
			rest = 0;
		}
	}

	std::reverse(temp.vect.begin(), temp.vect.end());
	temp.size_ = temp.vect.size();
	return temp;
}

int main() {

	auto number1 = bigInteger("114575");
	auto number2 = bigInteger("78524");

	auto result_1 = number1 + number2;
	std::cout << "sum: " << result_1 << std::endl; // 193'099

	auto result_2 = number2 * 2;
	std::cout << "mult: " << result_2 << std::endl; // 157'048

	return 0;
}

//конструктор перемещения;
//перемещающий оператор присваивания;
//оператор сложения двух больших чисел;
//оператор умножения на число.