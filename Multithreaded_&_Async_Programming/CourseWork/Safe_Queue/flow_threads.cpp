#include "Pool_potokov.h"

void Pool_potokov::work() {
	int x = kolvo_potokov_++;
	coord->at(x).X = x * 17;
	coord->at(x).Y = 5;
	m.lock();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord->at(x));
	Y1 std::cout << "ID потока:"; R1 std::cout << std::this_thread::get_id();
	m.unlock();
	while (vkl_otkl_pool) {
		std::function<void()>zadacha;
		if (ochered.pop(zadacha)) {
			try {
				m.lock();
				++coord->at(x).Y; G1;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord->at(x));
				zadacha(); W1;
				m.unlock();
			}
			catch (...) {
				std::cout << std::this_thread::get_id();
			}
		}
		else {
			std::this_thread::yield();
		}
	}
}

void Pool_potokov::inicializaciya(int init) {
	for (int i = 0; i < init; ++i) {
		coord->push_back(COORD());
		potok->emplace_back(std::thread(&Pool_potokov::work, this));
	}
}

void Pool_potokov::stop_() {
	vkl_otkl_pool = false;
	for (auto& p : *potok) {
		p.join();
	}
}

Pool_potokov::Pool_potokov() {}

Pool_potokov::~Pool_potokov() {
	stop_();
}

void Pool_potokov::pusk(int kolvo_potokov) {
	vkl_otkl_pool = true;
	inicializaciya(kolvo_potokov);
}

void Pool_potokov::add_potok(int plus_potok) {
	inicializaciya(plus_potok);
}

void Pool_potokov::stop() {
	stop_();
	potok->clear();
	kolvo_potokov_ = 0;
}

bool Pool_potokov::get_rabota_potokov() {
	return vkl_otkl_pool;
}

int Pool_potokov::get_kolvo_potokov() {
	return kolvo_potokov_;
}

