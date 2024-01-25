#include <iostream>
#include <thread>
#include <mutex>

class Data {
public:
	char ch;
	int i;
	double d;
	std::mutex m;
	Data (char q, int w, double e) : ch{ch}, i{i}, d{d} {}
	void print() {
		std::cout << "Ch = " << ch << " I = " << i << " D = " << d << "\n";
	}
};

static void swap_1(Data& obj1, Data& obj2) {
	char ch_1{}; int i_1{ 0 }; double d_1{0.0};
	std::lock(obj1.m, obj2.m);
	ch_1 = obj1.ch; obj1.ch = obj2.ch; obj2.ch = ch_1;
	i_1 = obj1.i; obj1.i = obj2.i; obj2.i = i_1;
	d_1 = obj1.d; obj1.d = obj2.d; obj2.d = d_1;
	obj1.m.unlock();
	obj2.m.unlock();
}

static void swap_2(Data& obj1, Data& obj2) {
	char ch_1{}; int i_1{ 0 }; double d_1{0.0};
	std::unique_lock<std::mutex> u1(obj1.m, std::defer_lock);
	std::unique_lock<std::mutex> u2(obj2.m, std::defer_lock);
	std::lock(u1, u2);
	ch_1 = obj1.ch; obj1.ch = obj2.ch; obj2.ch = ch_1;
	i_1 = obj1.i; obj1.i = obj2.i; obj2.i = i_1;
	d_1 = obj1.d; obj1.d = obj2.d; obj2.d = d_1;
}

static void swap_3(Data& obj1, Data& obj2) {
	char ch_1; int i_1; double d_1;
	std::scoped_lock<std::mutex,std::mutex> u1(obj1.m, obj2.m);
	ch_1 = obj1.ch; obj1.ch = obj2.ch; obj2.ch = ch_1;
	i_1 = obj1.i; obj1.i = obj2.i; obj2.i = i_1;
	d_1 = obj1.d; obj1.d = obj2.d; obj2.d = d_1;
}

static void func(void (*ptr_swap)(Data&, Data&), Data& obj1, Data& obj2) {
	for (int i = 0; i < 1000001; ++i)
		ptr_swap(obj1, obj2);
}

int main() {
	setlocale(0, "");
	{
		Data d1('1', 1, 1.0);
		Data d2('2', 2, 2.0);
		std::cout << "Начальные данные\n";
		std::cout << "d1: "; d1.print();
		std::cout << "d2: "; d2.print();
		std::cout << "Результат swap_1 \n";

		std::thread t1(func, swap_1, std::ref(d1), std::ref(d2));
		std::thread t2(func, swap_1, std::ref(d1), std::ref(d2));
		std::thread t3(func, swap_1, std::ref(d2), std::ref(d1));
		t1.join();
		t2.join();
		t3.join();

		std::cout << "d1: "; d1.print();
		std::cout << "d2: "; d2.print();
	}

	{
		std::cout << "\n";
		Data d1('1', 1, 1.0);
		Data d2('2', 2, 2.0);
		std::cout << "Начальные данные\n";
		std::cout << "d1: "; d1.print();
		std::cout << "d2: "; d2.print();
		std::cout << "Результат swap_2 \n";

		std::thread t1(func, swap_2, std::ref(d1), std::ref(d2));
		std::thread t2(func, swap_2, std::ref(d1), std::ref(d2));
		std::thread t3(func, swap_2, std::ref(d2), std::ref(d1));
		t1.join();
		t2.join();
		t3.join();

		std::cout << "d1: "; d1.print();
		std::cout << "d2: "; d2.print();
	}

	{
		std::cout << "\n";
		Data d1('1', 1, 1.0);
		Data d2('2', 2, 2.0);
		std::cout << "Начальные данные\n";
		std::cout << "d1: "; d1.print();
		std::cout << "d2: "; d2.print();
		std::cout << "Результат swap_3 \n";

		std::thread t1(func, swap_3, std::ref(d1), std::ref(d2));
		std::thread t2(func, swap_3, std::ref(d1), std::ref(d2));
		std::thread t3(func, swap_3, std::ref(d2), std::ref(d1));
		t1.join();
		t2.join();
		t3.join();

		std::cout << "d1: "; d1.print();
		std::cout << "d2: "; d2.print();
	}
	return EXIT_SUCCESS;
}