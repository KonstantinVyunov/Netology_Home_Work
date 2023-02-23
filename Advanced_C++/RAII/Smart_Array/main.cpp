#include <iostream>

class SmartArray {
private:
	int* arr;
	size_t size = NULL;
	int index = NULL;
public:
	SmartArray(int& num) : size(num) {
		arr = new int[size];
	}
	void addElement(int num) {
		if (index < size) {
			arr[index++] = num;
		} else {
			throw std::exception("The array is full.");
		}
		return;
	}

	void deleteBackElement() {
		if (index > NULL) {
			arr[--index] = 0;
		} else {
			throw std::exception("The array is empty.");
		}
		return;
	}

	int getElement(int index_) const {
		return (index_ < size) ? (arr[index_]) : (throw std::exception("Requested index is out of range."));
	}

	int operator[](int index_) {
		return arr[index_];
	}

	~SmartArray() {
		delete[] arr;
	}
};

int main(int argc, char** argv) {
	int num = 5;
	try {
		SmartArray smart_array(num);
		smart_array.addElement(1);
		smart_array.addElement(4);
		smart_array.addElement(155);
		smart_array.addElement(14);
		smart_array.addElement(15);

		for (int i = 0; i < num; ++i) {
			std::cout << smart_array.getElement(i) << ' ';
		}

		std::cout << std::endl;
		smart_array.deleteBackElement();
		smart_array.deleteBackElement();
		smart_array.deleteBackElement();
		smart_array.deleteBackElement();
		smart_array.deleteBackElement();

		for (int i = 0; i < num; ++i) {
			std::cout << smart_array[i] << ' ';
		}
	}
	catch (const std::exception& ex) {
		std::cerr << "Error: " << ex.what() << std::endl;
	}

	return 0;
}