// Program takes addresses from the "in.txt" file, reorders them upside down, and saves into the "out.txt" file.

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

class Address {
	friend void print(Address* list, const int address_quantity);
private:
	std::string city;
	std::string street;
	int building = 0;
	int appartment = 0;
public:
	Address() : Address("city", "street", 0, 0) {}
	Address(std::string city, std::string street, int building, int appartment) {
		this->city = city;
		this->street = street;
		this->building = building;
		this->appartment = appartment;
	}

	const std::string get_stringed_address() {
		return this->city + ' ' + this->street + ' ' + std::to_string(this->building) + ' ' + std::to_string(this->appartment);
	}
};

std::string* readFile(int& address_quantity) {
	std::string* addresses = nullptr;
	std::ifstream file("in.txt");
	if (!file.is_open()) {
		std::cout << "Cannot open the file \"in.txt\"!" << std::endl;
	} else {
		file >> address_quantity;
		const size_t FIELDS_IN_ADDRESS = 4;
		int total_input_rows = FIELDS_IN_ADDRESS * address_quantity;
		addresses = new std::string[total_input_rows];
		for (size_t i = 0; i < total_input_rows; ++i) {
			file >> addresses[i];
		}
		file.close();
	}
	return addresses;
}

Address* createList(std::string* raw_addresses, int address_quantity) {
	const size_t FIELDS_IN_ADDRESS = 4;
	int total_input_rows = FIELDS_IN_ADDRESS * address_quantity;
	Address* list = new Address[address_quantity];
	for (int i = 0, j = 0; i < address_quantity && j < total_input_rows; ++i, j += 4) {
		list[i] = {raw_addresses[j+0], raw_addresses[j+1], stoi(raw_addresses[j+2]), stoi(raw_addresses[j+3])};
	}
	return list;
}

void print(Address* list, const int address_quantity) {
	for (int i = 0; i < address_quantity; ++i) {
		std::cout << list[i].city << ' ' << list[i].street << ' ' << list[i].building << ' ' << list[i].appartment << ' ' << std::endl;
	}
	return;
}

void writeFile(Address* list, const int address_quantity) {
	std::ofstream file("out.txt");
	file << address_quantity << std::endl;
	for (int i = address_quantity - 1; i >= 0; --i) {
		file << list[i].get_stringed_address() << std::endl;
	}
	file.close();
	return;
}

int main(int argc, char** argv) {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	int address_quantity = 0;
	std::string* raw_addresses = readFile(address_quantity);
	Address* list = createList(raw_addresses, address_quantity);
	writeFile(list, address_quantity);
	print(list, address_quantity);
	delete[] raw_addresses;
	delete[] list;
	return 0;
}