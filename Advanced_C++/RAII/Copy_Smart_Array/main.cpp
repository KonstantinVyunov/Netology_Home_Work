#include <iostream>

class SmartArray {
private:
	int* arr;
	size_t size = NULL;
	int index = NULL;
public:
	SmartArray(int num) : size(num) {
		arr = new int[size];
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
		if (index > NULL) {
			arr[--index] = 0;
		} else {
			throw std::exception("The array is empty.");
		}
		return;
	}

	int size_arr() { return this->index; }

	int getElement(int index_) const {
		return (index_ < size) ? (arr[index_]) : (throw std::exception("Requested index is out of range."));
	}

	int operator[](int index_) { return arr[index_]; }

	SmartArray& operator=(const SmartArray& rvalue) {
		int* temp_arr = new int[this->size];
		for (int i = 0; i < this->size; ++i) {
			temp_arr[i] = rvalue.arr[i];
		}
		this->arr = temp_arr;
		return *this;
	}

	~SmartArray() {
		delete[] arr;
	}
};

int main(int argc, char** argv) {

	SmartArray arr(5);
	arr.addElement(1);
	arr.addElement(4);
	arr.addElement(155);
	arr.addElement(200);

	std::cout << "arr:\t";
	for (int i = 0; i < arr.size_arr(); ++i) {
		std::cout.width(3);
		std::cout << arr[i] << '|';
	}

	std::cout << std::endl;
	std::cout << "new_arr:";
	SmartArray new_array(5);
	new_array.addElement(44);
	new_array.addElement(34);
	new_array.addElement(44);
	new_array.addElement(34);
	new_array.addElement(34);

	for (int i = 0; i < new_array.size_arr(); ++i) {
		std::cout.width(3);
		std::cout << new_array[i] << '|';
	}

	arr = new_array;

	std::cout << std::endl;
	std::cout << "arr:\t";
	for (int i = 0; i < arr.size_arr(); ++i) {
		std::cout.width(3);
		std::cout << arr[i] << '|';
	}

	return 0;
}