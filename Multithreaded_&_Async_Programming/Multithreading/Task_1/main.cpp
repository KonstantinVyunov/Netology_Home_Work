#include <thread>
#include <chrono>
#include <iostream>

int main() {
	std::cout << "Enter how many clients we expect toady: ";
	int clients = 0, counter = 0;
	std::cin >> clients;
	std::thread([&] {
		for (int i = 1; i <= clients; ++i) {
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "MESSAGE_#" << std::this_thread::get_id() << ": got a new client\t";
			std::cout << "\tClients in line: " << ++counter << "\tClients served toady: " << i << std::endl;
			if (i == clients) {
				std::cout << "\nNO NEW CLIENTS FOR TODAY!\n" << std::endl;
			}
		}
	}).detach();

	bool flag = true;
	while (flag) {
		std::this_thread::sleep_for(std::chrono::seconds(2));
		if (counter) {
			std::cout << "MESSAGE_#" << std::this_thread::get_id() << ": client is taken in processing\t";
			std::cout << "Clients in line: " << --counter << std::endl;
		} else {
			flag = false;
		}
	}
	return EXIT_SUCCESS;
}