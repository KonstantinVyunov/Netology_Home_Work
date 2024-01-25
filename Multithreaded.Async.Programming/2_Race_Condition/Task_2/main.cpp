#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

#include <Windows.h>

std::mutex mut;

int main() {
<<<<<<< HEAD:Multithreaded_&_Async_Programming/2_Race_Condition/Task_2/main.cpp
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
=======
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);//����������� �� �������
>>>>>>> 7db6a4589789673533ecddc89fd963792e41d40b:Multithreaded.Async.Programming/2_Race_Condition/Task_2/main.cpp
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);

<<<<<<< HEAD:Multithreaded_&_Async_Programming/2_Race_Condition/Task_2/main.cpp
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
=======
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
>>>>>>> 7db6a4589789673533ecddc89fd963792e41d40b:Multithreaded.Async.Programming/2_Race_Condition/Task_2/main.cpp
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
<<<<<<< HEAD:Multithreaded_&_Async_Programming/2_Race_Condition/Task_2/main.cpp
		std::lock_guard<std::mutex> g(mut);
		std::cout << " time:" << " ";
		std::cout << elapsed_seconds.count() << "s\t";
=======
		std::lock_guard<std::mutex> g(m);
		std::cout << " ����� �������: " << " "; R1 std::cout << elapsed_seconds.count() << "s\t"; W1
>>>>>>> 7db6a4589789673533ecddc89fd963792e41d40b:Multithreaded.Async.Programming/2_Race_Condition/Task_2/main.cpp
		};
	for (int i = 0; i < thread_num; ++i)
		vect.emplace_back(function, i, 5 + rand() % 10);
	for (auto& elm : vect)
		elm.join();
	COORD coord{0,thread_num};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	return EXIT_SUCCESS;
}