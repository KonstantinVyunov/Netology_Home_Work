// Program takes addresses from the "in.txt" file, reorder them, and saves into the "out.txt" file.

#include <iostream>
#include <fstream>
#include <string>

class Address {
private:
	std::string city;
	std::string street;
	int building = 0;
	int appartment = 0;
public:
	Address() {}
	Address(std::string city, std::string street, int building, int appartment) {
		this->city = city;
		this->street = street;
		this->building = building;
		this->appartment = appartment;
	}

	std::string set_stringed_address() {
		return this->city + ", " + this->street + ", " + std::to_string(this->building) + ", " + std::to_string(this->appartment);
	}
};

std::string* readFile(int& address_quantity) {
	std::string* addresses = nullptr;
	std::ifstream file("in.txt");
	if (!file.is_open()) {
		std::cout << "Cannot open the file \"in.txt\"!" << std::endl;
	} else {
		file >> address_quantity;
		int limit = 4 * address_quantity;
		addresses = new std::string[limit];
		for (int i = 0; i < limit; ++i) {
			file >> addresses[i];
		}
		file.close();
	}
	return addresses;
}

Address* createList(std::string* raw_addresses, int address_quantity) {
	int limit = 4 * address_quantity;
	Address* list = new Address[address_quantity];
	for (int i = 0, j = 0; i < address_quantity && j < limit; ++i, j += 4) {
		list[i] = { raw_addresses[j + 0], raw_addresses[j + 1], stoi(raw_addresses[j + 2]), stoi(raw_addresses[j + 3]) };
	}
	return list;
}

void sortList(Address *list, int address_quantity) {
	for (int i = 0; i < address_quantity-1; ++i) {
		for (int j = i+1; j < address_quantity; ++j) {
			if (list[i].set_stringed_address() > list[j].set_stringed_address()) {
				std::swap(list[i], list[j]);
			}
		}
	}
	return;
}

void writeFile(Address* list, const int address_quantity) {
	std::ofstream file("out.txt");
	file << address_quantity << std::endl;
	for (int i = 0; i < address_quantity; ++i) {
		file << list[i].set_stringed_address() << std::endl;
	}
	file.close();
	return;
}

int main(int argc, char** argv) {
	int address_quantity = 0;
	std::string* raw_addresses = readFile(address_quantity);
	Address* list = createList(raw_addresses, address_quantity);
	sortList(list, address_quantity);
	writeFile(list, address_quantity);
	delete[] raw_addresses;
	delete[] list;
	return 0;
}