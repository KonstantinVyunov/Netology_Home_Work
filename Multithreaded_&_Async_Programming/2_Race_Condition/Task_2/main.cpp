#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

#include <Windows.h>

std::mutex mut;

int main() {
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);

	srand(time(NULL));
	std::vector<std::thread> vect;
	const int thread_num = 20;
	COORD mass[thread_num]{};
	auto function = [&](int thread, int size) {
		auto start = std::chrono::steady_clock::now();
		mass[thread].X = 0;
		mass[thread].Y = thread;
		mut.lock();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mass[thread]);
		std::cout << "thread #";
		std::cout << thread;
		std::cout << "\tthread ID: ";
		std::cout << std::this_thread::get_id() << " \t ";
		mut.unlock();
		CONSOLE_SCREEN_BUFFER_INFO x;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &x);
		mass[thread].X = x.dwCursorPosition.X;
		for (int i = 0; i < size; ++i) {
			std::this_thread::sleep_for(std::chrono::milliseconds(size * 100));
			++mass[thread].X;
			std::lock_guard<std::mutex> g(mut);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mass[thread]);
			std::cout << "=";
		}
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::lock_guard<std::mutex> g(mut);
		std::cout << " time:" << " ";
		std::cout << elapsed_seconds.count() << "s\t";
		};
	for (int i = 0; i < thread_num; ++i)
		vect.emplace_back(function, i, 5 + rand() % 10);
	for (auto& elm : vect)
		elm.join();
	COORD coord{0,thread_num};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	return EXIT_SUCCESS;
}