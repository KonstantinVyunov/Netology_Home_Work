#include <iostream>
#include <thread>
#include <mutex>

class Data {
public:
	char q;
	int w;
	double e;
	std::mutex m;
	Data (char q, int w, double e) : q{ q }, w{ w }, e{ e } {}
	void print() {
		std::cout << "Q=" << q << " W=" << w << " E=" << e << "\n";
	}
};

void swap_1(Data& obj1, Data& obj2) {
	char q1; int w1; double e1;
	std::lock(obj1.m, obj2.m);
	q1 = obj1.q; obj1.q = obj2.q; obj2.q = q1;
	w1 = obj1.w; obj1.w = obj2.w; obj2.w = w1;
	e1 = obj1.e; obj1.e = obj2.e; obj2.e = e1;
	obj1.m.unlock();
	obj2.m.unlock();
}

void swap_2(Data& obj1, Data& obj2) {
	char q1; int w1; double e1;
	std::unique_lock<std::mutex> u1(obj1.m, std::defer_lock);
	std::unique_lock<std::mutex> u2(obj2.m, std::defer_lock);
	std::lock(u1, u2);
	q1 = obj1.q; obj1.q = obj2.q; obj2.q = q1;
	w1 = obj1.w; obj1.w = obj2.w; obj2.w = w1;
	e1 = obj1.e; obj1.e = obj2.e; obj2.e = e1;
}

void swap_3(Data& obj1, Data& obj2) {
	char q1; int w1; double e1;
	std::scoped_lock<std::mutex,std::mutex> u1(obj1.m, obj2.m);
	q1 = obj1.q; obj1.q = obj2.q; obj2.q = q1;
	w1 = obj1.w; obj1.w = obj2.w; obj2.w = w1;
	e1 = obj1.e; obj1.e = obj2.e; obj2.e = e1;
}

void func(void (*ptr_swap)(Data&, Data&), Data& obj1, Data& obj2) {
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
		std::cout << "\n\n";
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
		std::cout << "\n\n";
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
}