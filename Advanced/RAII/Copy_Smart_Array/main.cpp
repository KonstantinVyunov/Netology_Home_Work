#include <iostream>

class SmartArray {
private:
	int* arr = nullptr;
	size_t size = 0;
	int index = 0;
public:

	SmartArray(int num) : size(num) {
		arr = new int[size];
	}

	SmartArray(const SmartArray& arr) : size(arr.size), index(arr.index) {
		this->arr = new int[size];
		for (int i = 0; i < index; ++i) {
			this->arr[i] = arr.arr[i];
		}
	}

	void addElement(int num) {
		if (index < size) {
			this->arr[index++] = num;
		}
		else {
			throw std::exception("The array is full.");
		}
		return;
	}

	void deleteBackElement() {
		if (index > 0) {
			arr[--index] = 0;
		} else {
			throw std::exception("The array is empty.");
		}
		return;
	}

	int size_arr() const { return this->index; }

	int getElement(int index) const {
		if ((index >= 0) && (index < this->index)) {
			return arr[index];
		}
		else {
			throw std::exception("Requested index is out of range.");
		}
	}

	int operator[](int index) const {
		return getElement(index);
	}

	SmartArray& operator=(const SmartArray& rvalue) {
		if (this == &rvalue) { return *this; }

		int* temp_arr = new int[rvalue.size];
		for (int i = 0; i < rvalue.size; ++i) {
			temp_arr[i] = rvalue.arr[i];
		}
		delete[] this->arr;				// clean arr memory before overwriting
		std::swap(this->arr, temp_arr); // swap the ptr and simultaneously clean the temp_arr
		this->size = rvalue.size;
		this->index = rvalue.index;
		return *this;
	}

	virtual ~SmartArray() {
		delete[] arr;
	}
};

int main(int argc, char** argv) {

	SmartArray arr(6);
	arr.addElement(1);
	arr.addElement(4);
	arr.addElement(155);

	// operator "="
	SmartArray new_arr_1(8);
	new_arr_1 = arr;
	for (int i = 0; i < new_arr_1.size_arr(); ++i) {
		std::cout << new_arr_1[i] << ' ';
	}

	std::cout << std::endl;

	// constructor
	SmartArray new_arr_2(arr);
	for (int i = 0; i < new_arr_2.size_arr(); ++i) {
		std::cout << new_arr_2[i] << ' ';
	}

	return 0;
}