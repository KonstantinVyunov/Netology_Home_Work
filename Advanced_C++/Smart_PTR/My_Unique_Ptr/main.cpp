#include <iostream>

template<class T>
class MyUniquePtr {
private:
	T* smart_ptr = nullptr;
	
public:
	MyUniquePtr(T* ptr) : smart_ptr(std::move(ptr)) {}

	MyUniquePtr(const MyUniquePtr& other) = delete;
	MyUniquePtr& operator=(const MyUniquePtr& other) = delete;
	
	T& operator*() { return *smart_ptr; }
	const T& operator*() const { return *smart_ptr; }

	T* release() noexcept {
		T* temp_ptr = nullptr;
		return std::exchange(smart_ptr, temp_ptr);
	}

	~MyUniquePtr() {
		std::cout << "memory released" << std::endl;
		delete smart_ptr;
	}
}; 

int main(int argc, char** argv) {
	int* i_ptr = new int(3);
	std::cout << "Raw pointer: " << i_ptr << std::endl;

	MyUniquePtr<int> m(i_ptr);
	std::cout << "Get value: " << *m << std::endl;
	std::cout << "Release ptr: " << m.release() << std::endl;

	delete i_ptr;

	return EXIT_SUCCESS;
}