//STRUCT OUTPUT. Program asks the user to fill in his address and then outputs it.
#include <iostream>

struct Address {
	std::string City = { "Moscow" };
	std::string Street = {};
	int Building_Num = 0;
	int Flat_Num = 0;
	int Index = 0;
};

void getAddress(Address& address) {
	std::cout << "Please fill out your address data.\n" << std::endl;
	std::cout << "City:\t";
	std::cin >> address.City;
	std::cout << "St:\t";
	std::cin >> address.Street;
	std::cout << "Bldg:\t";
	std::cin >> address.Building_Num;
	std::cout << "Flt:\t";
	std::cin >> address.Flat_Num;
	std::cout << "Index:\t";
	std::cin >> address.Index;
	return;
}

void printAddress(const Address& address) {
	std::cout << "City:\t" << address.City << std::endl;
	std::cout << "St:\t" << address.Street << std::endl;
	std::cout << "Bldg:\t" << address.Building_Num << std::endl;
	std::cout << "Flt:\t" << address.Flat_Num << std::endl;
	std::cout << "Index:\t" << address.Index << std::endl;
	return;
}

int main(int argc, char** argv) {
	
	Address address;
	getAddress(address);
	std::cout << std::endl;
	printAddress(address);

	return 0;
}