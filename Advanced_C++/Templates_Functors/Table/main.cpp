#include <iostream>
#include <cassert>

template<class Type>
class Table {
private:
	size_t rows;
	size_t columns;
	Type** table = nullptr;

public:
	Table() = default;
	Table(size_t rows, size_t columns)
		: rows(rows), columns(columns), table(new Type* [rows])
	{
		for (int i = 0; i < this->rows; ++i) {
			table[i] = new Type[this->columns];
		}
	}

	Type* operator[](const int& index) const {
		assert(index >= 0 && (index < rows && index < columns));
		return table[index];
	}
	
	size_t size() const {
		return (rows * columns);
	}

	virtual ~Table() {
		for (int i = 0; i < this->rows; ++i) {
			delete[] table[i];
		}
		delete[] table;
	}
};

int main(int argc, char** argv) {
	Table<int> table(2, 3);
	
	table[1][3] = 3;
	std::cout << table[1][3] << std::endl;

	std::cout << "Size: " << table.size() << std::endl;

	return EXIT_SUCCESS;
}