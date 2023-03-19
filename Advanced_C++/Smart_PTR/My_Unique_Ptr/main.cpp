#include <iostream>
#include <memory>

template<class T>
class MyUniquePtr {
public:
	T* ptr_ = nullptr;
	
public:
	MyUniquePtr(T* ptr) : ptr_(ptr) {
		T* temp = nullptr;

	}

	MyUniquePtr(const MyUniquePtr& other) = delete;
	MyUniquePtr& operator=(const MyUniquePtr& other) = delete;
	
	T& operator*() { return *ptr_; }
	const T& operator*() const { return *ptr_; }

	const T& operator[](const int& index) const { return ptr_[index]; }
	T& operator[](const int& index) { return ptr_[index]; }

	T* release() {
		T* temp_ptr = ptr_;
		delete ptr_;
		return temp_ptr;
	}

	~MyUniquePtr() {
		std::cout << "memory released" << std::endl;
		delete[] ptr_;
	}
}; 

int main(int argc, char** argv) {
	int* i_ptr = new int[3] {1, 2, 3};
	std::cout << "Original address: " << i_ptr << std::endl;

	MyUniquePtr<int> m(i_ptr);
	std::cout << "  Passed address: " << &m << std::endl;
	std::cout << "  Index value: " << m[2] << std::endl;
	
	delete[] i_ptr;

	return EXIT_SUCCESS;
}


//Конструктор, принимающий сырой указатель. - done!
//Перегружен оператор* для получения объекта.
//Запрещены оператор присваивания и конструктор копирования. - done!
//Метод release, который освобождает владение и возвращает сырой указатель.
//Деструктор.