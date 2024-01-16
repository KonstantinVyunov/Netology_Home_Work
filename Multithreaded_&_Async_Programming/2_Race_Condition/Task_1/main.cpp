#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

int main() {
	std::atomic<int> counter{0};
	std::thread([&] {
		for (int i = 1; i <= 10; ++i) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1'000));
			std::cout << "Thread's ID: " << std::this_thread::get_id();
			std::cout << "\nClients quantity: " << ++counter << "\tCycles quantity: " << i << std::endl;
		}
	}).detach();

	bool flag = true;
	std::thread([&] {
		while (flag) {
			std::this_thread::sleep_for(std::chrono::milliseconds(2'000));
			if (counter) {
				std::cout << "Thread's ID: " << std::this_thread::get_id() << std::endl;
				std::cout << "Cycles quantity: " << --counter << std::endl;
			} else {
				flag = false;
			}
		}
	}).join();

	return EXIT_SUCCESS;
};