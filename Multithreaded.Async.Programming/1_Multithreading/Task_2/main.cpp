#include<iostream>
#include<thread>
#include<chrono>
#include<vector>

class Total_time {
private:
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
public:
	Total_time() {
		start = std::chrono::steady_clock::now();
	}
	~Total_time() {
		end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed_seconds = (end - start);
		std::cout << "\t" << elapsed_seconds.count() << "s\t";
	}
};

static void my_thread(std::vector<int>& vect_1, std::vector<int>& vect_2, int start, int size, int step) {
	for (start; start < size; (start += step)) {
		vect_1[start] = (vect_1[start] + vect_2[start]);
		return;
	}
}

static void sum_of_vect(int size_of_thread) {
	for (int i = 1'000; i <= 1'000'000; i *= 10) {
		std::vector<std::thread> v_thrs;
		std::vector<int> vect_1(i, i);
		std::vector<int> vect_2(i, i);
		Total_time t_t;
		for (int j = 0; j < size_of_thread; ++j) {
			v_thrs.emplace_back(my_thread, std::ref(vect_1), std::ref(vect_2), j, i, size_of_thread);
		}
		for (auto& thr : v_thrs) {
			thr.join();
		}
	}
}

int main() {
	std::cout << "Hardware cores: " << std::thread::hardware_concurrency() << std::endl;
	std::cout << "\n\t\t1'000" << "\t\t\t10'000" << "\t\t\t100'000" << "\t\t\t1'000'000";
	for (int i = 1; i <= 16; i *= 2) {
		std::cout << std::endl << i << " threads:";
		sum_of_vect(i);
	}
	return EXIT_SUCCESS;
}