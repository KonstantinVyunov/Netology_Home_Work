#include <iostream>
#include <list>
#include <thread>
#include <future>
#include <chrono>
#include "Define.h"

void poisk_min(std::list<int>::iterator it_s, std::list<int>::iterator it_e, std::promise<std::list<int>::iterator>& pr_obj) {
    std::list<int>::iterator it;
    it = it_s;
    for (; it_s != it_e; ++it_s) {
        if (*it > *it_s)
            it = it_s;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    pr_obj.set_value(it);
}

int main() {
    std::list<int> in_out{ 10, 30, 20, -40, 60, -10, 80, -70, 100, 1 };
    Y1 std::cout << "start List: "; W1
        for (auto x : in_out)
            std::cout << x << " ";
    std::cout << "\n";
    for (auto it = in_out.begin(); it != in_out.end(); ++it) {
        std::promise<std::list<int>::iterator> pr_obj;
        std::future<std::list<int>::iterator> futureObj = pr_obj.get_future();
        std::thread t(poisk_min, it, in_out.end(), std::ref(pr_obj));
        std::swap(*it, *futureObj.get());
        G1 std::cout << "="; W1
            t.join();
    }
    std::cout << "\n";
    Y1 std::cout << "sort List: "; W1
        for (auto x : in_out)
            std::cout << x << " ";
    return 0;
}

//std::list<int>::iterator poisk_min(std::list<int>::iterator it_s, std::list<int>::iterator it_e) {
//    std::list<int>::iterator it;
//    it = it_s;
//    for (; it_s != it_e; ++it_s) {
//        if (*it > *it_s)
//            it = it_s;
//    }
//    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//    return it;
//}
//
//int main() {
//    std::list<int> in_out {10, 30, 20, -40, 60, -10, 80, -70, 100, 1};
//    std::cout << "start List: ";
//    for (auto x : in_out)
//        std::cout << x << " ";
//    std::cout << "\n";
//    for (auto it = in_out.begin(); it != in_out.end(); ++it) {
//        auto futureObj = std::async(poisk_min, it, in_out.end());       
//        std::swap(*it, *futureObj.get());
//        std::cout << "=";       
//    }
//    std::cout << "\n";
//    std::cout << "sort List: ";
//    for (auto x : in_out)
//        std::cout << x << " ";
//    return 0;
//}
