#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

#include <Windows.h>
#include "Define.h"

std::mutex m;

int main() {
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);//����������� �� �������
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);

	setlocale(0, "");
	srand(time(0));//������ ������ �������
	std::vector<std::thread> th;
	const int kolvo_potokov = 20;
	COORD mass[kolvo_potokov];
	auto func = [&](int potok, int dlinna) {
		auto start = std::chrono::steady_clock::now();
		mass[potok].X = 0;
		mass[potok].Y = potok;
		m.lock();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mass[potok]);
		std::cout << "����� ������: "; Y1 std::cout << potok; W1 std::cout << "  ID ������: "; Y1 std::cout << std::this_thread::get_id() << "\t "; W1
			m.unlock();
		CONSOLE_SCREEN_BUFFER_INFO x;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &x);
		mass[potok].X = x.dwCursorPosition.X;
		for (int i = 0; i < dlinna; ++i) {
			std::this_thread::sleep_for(std::chrono::milliseconds(dlinna * 100));
			++mass[potok].X;
			std::lock_guard<std::mutex> g(m);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mass[potok]);
			G1 std::cout << "="; W1
		}
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		std::lock_guard<std::mutex> g(m);
		std::cout << " ����� �������: " << " "; R1 std::cout << elapsed_seconds.count() << "s\t"; W1
		};
	for (int i = 0; i < kolvo_potokov; ++i)
		th.emplace_back(func, i, 5 + rand() % 10);
	for (auto& t : th)
		t.join();
	COORD coord{ 0,kolvo_potokov };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	return EXIT_SUCCESS;
}