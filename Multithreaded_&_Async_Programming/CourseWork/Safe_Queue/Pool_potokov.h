#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <functional>
#include <chrono>
#include"Zagruzka_zadach.h"
#include<Windows.h>
#include"Define.h"
#define time_main  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
static std::mutex m;

class Pool_potokov {
private:
	std::atomic<int> kolvo_potokov_ = 0;
	std::atomic<bool> vkl_otkl_pool = false;
	std::vector<COORD>* coord = new std::vector<COORD>;
	std::vector<std::thread>* potok = new std::vector<std::thread>;
	Zagruzka_zadach<std::function<void()>> ochered;
	void work();
	void inicializaciya(int init);
	void stop_();
public:
	Pool_potokov();
	~Pool_potokov();
	void pusk(int kolvo_potokov);
	void add_potok(int plus_potok);
	void stop();
	bool get_rabota_potokov();
	int get_kolvo_potokov();
	template<typename Func_Tip >
	void submit(Func_Tip fn) {
		ochered.push(Func_Tip(fn));
	}
};

