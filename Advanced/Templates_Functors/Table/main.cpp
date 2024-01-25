#include <iostream>
#include <cassert>
#include <exception>

template<class Type>
class Table {
private:
	size_t rows;
	size_t columns;
	Type** table = nullptr;

public:
	Table(const Table& table)
		: rows(table.rows), columns(table.columns), table(new Type*[table.rows])
	{
		for (int i = 0; i < this->rows; ++i) {
			this->table[i] = new Type[this->columns];
			for (int j = 0; j < this->columns; ++j) {
				this->table[i][j] = table[i][j];
			}
		}
	}

	Table(size_t rows, size_t columns)
		: rows(rows), columns(columns), table(new Type* [rows])
	{
		for (int i = 0; i < this->rows; ++i) {
			table[i] = new Type[this->columns];
			for (int j = 0; j < this->columns; ++j) {
				table[i][j] = 0;
			}
		}
	}

	Table& operator=(const Table& table) {
		if (this == &table) {
			return *this;
		} else {
			for (int i = 0; i < rows; ++i) {
				delete[] this->table[i];
			}
			delete[] table;
			this->table = nullptr;
			std::swap(table, this->table);
			return *this;
		}
	}

	Type* operator[](const int& index) {
		assert(index >= 0 && index < rows);
		return table[index];
	}

	const Type* operator[](const int& index) const {
		assert(index >= 0 && index < rows);
		return table[index];
	}
	
	size_t size() const {
		return (rows * columns);
	}

	virtual ~Table() {
		for (int i = 0; i < rows; ++i) {
			delete[] table[i];
		}
		delete[] table;
	}
};

template<typename Type>
Table<Type> tablet(Type rows, Type columns) {
	Table<Type> tab(rows, columns);
	return tab;
}

int main(int argc, char** argv) {
	auto test = tablet<int>(3, 3);
	test[1][2] = 3;

	std::cout << "   Get array[1][2]: " << test[1][2] << std::endl;
	std::cout << "Overall Table Size: " << test.size() << std::endl;

	return EXIT_SUCCESS;
}