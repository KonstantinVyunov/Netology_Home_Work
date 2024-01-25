#pragma once
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <memory>
template<class _Tip>
class Zagruzka_zadach {
private:
	std::mutex m;
	std::queue<_Tip> ochered;
	//std::condition_variable c_v;// с преподавателем согласовано без этой штуки.
public:
	Zagruzka_zadach();
	void push(_Tip func);
	bool pop(_Tip&);
};

template<class _Tip>
Zagruzka_zadach<_Tip>::Zagruzka_zadach() {}

template<class _Tip>
void Zagruzka_zadach<_Tip>::push(_Tip func) {
	std::unique_lock<std::mutex> l_g(m);
	ochered.push(func);
}

template<class _Tip>
bool Zagruzka_zadach<_Tip>::pop(_Tip& value) {
	std::lock_guard<std::mutex> lk(m);
	if (ochered.empty())
		return false;
	value = std::move(ochered.front());
	ochered.pop();
	return true;
}


