#include <iostream>
#include <exception>
#include <vector>

template<class Type>
class MyVector {
private:
	size_t overall_size = 0;
	size_t available_size = 0;
	size_t index = 0;
	Type* vect = nullptr;
public:
	MyVector(const size_t size) : available_size(size), overall_size(size) {
		if (size == 0) {
			available_size = 1;
			overall_size = 1;
			vect = new Type[1]{0};
		} else {
			vect = new Type[size];
			for (size_t i = 0; i < overall_size; ++i) {
				vect[i] = 0;
			}
		}
	}

	MyVector(const MyVector<Type>& vect)
		: overall_size(vect.overall_size),
		  available_size(vect.available_size),
		  index(vect.index),
		  vect(new Type[vect.overall_size])
	{
		for (size_t i = 0; i < this->index; ++i) {
			this->vect[i] = vect[i];
		}
	}

	MyVector() : MyVector(0) {}

	MyVector<Type>& operator=(const MyVector<Type>& rval) {
		if (this == &rval) { return *this; }

		Type* temp_vect = new Type[rval.index];
		for (int i = 0; i < rval.index; ++i) {
			temp_vect[i] = rval.vect[i];
		}
		delete[] this->vect;
		std::swap(this->vect, temp_vect);

		this->index = rval.index;
		this->overall_size = rval.index;
		this->available_size = rval.index;
		return *this;
	}

	virtual size_t capacity() const {
		return overall_size;
	}

	virtual size_t size() const {
		return index;
	}

	const Type& operator[](const size_t index) const {
		if (index > available_size) { throw std::exception("Invalid index for []."); }
		return this->vect[index];
	}

	Type& operator[](const size_t index) {
		if (index > available_size) { throw std::exception("Invalid index for []."); }
		return this->vect[index];
	}

	virtual Type& at(const size_t index) {
		if (index > this->available_size) { throw std::exception("Invalid index for at() method."); }
			return this->vect[index];
	}

	virtual void push_back(const Type& value) {
		if (index == available_size && available_size == overall_size) {
			Type* temp_vect = new Type[2 * overall_size];
			for (size_t i = 0; i < overall_size; ++i) {
				temp_vect[i] = this->vect[i];
			}
			delete[] vect;
			vect = nullptr;
			std::swap(vect, temp_vect);
			this->overall_size *= 2;
			vect[index++] = value;
			this->available_size = index;
		} else {
			if (index < available_size) {
				vect[index++] = value;
			} else {
				vect[index++] = value;
				++available_size;
			}
		}
		return;
	}

	virtual Type& back() {
		return vect[this->index];
	}

	virtual ~MyVector() {
		delete[] vect;
	}
};

int main(int argc, char** argv) {
	try {
		MyVector<int> my_vector;

		std::cout << "Capacity: ";
		std::cout << my_vector.capacity() << std::endl;

		std::cout << "Size: ";
		std::cout << my_vector.size() << std::endl;

		std::cout << "Push_back: {9, 7, 5, 11, 15, 20}" << std::endl;
		my_vector.push_back(9);
		my_vector.push_back(7);
		my_vector.push_back(5);
		my_vector.push_back(11);
		my_vector.push_back(15);
		my_vector.push_back(20);

		for (size_t i = 0; i < my_vector.size(); ++i) {
			std::cout << "in[" << i << "] = " << my_vector[i] << std::endl;
		}

		std::cout << ".at(1): ";
		my_vector.at(1) = 7;
		std::cout << my_vector.at(1) << std::endl;

		std::cout << "Capacity: ";
		std::cout << my_vector.capacity() << std::endl;

		std::cout << "Size: ";
		std::cout << my_vector.size() << std::endl;
	}
	catch (const std::exception& error) {
		std::cerr << "\nError description: " << error.what() << std::endl;
	}

	MyVector<int> my_vector;
	MyVector<int> my_vector2;
	my_vector2 = my_vector;

	return EXIT_SUCCESS;
}