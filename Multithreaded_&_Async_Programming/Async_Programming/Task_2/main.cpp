#include <iostream>
#include<algorithm>
#include<list>
#include<future>
#include<chrono>
#include"Define.h"


void foo(int& a) {
    a *= 2;
}

namespace gdp {
    template<class Q, class U>
    void for_each_main(Q start, Q end, void(*f)(U)) {
        for (; start != end; ++start) {
            f(*start);
        }
    }
}

namespace gdp {
    template<class Q, class U>
    void for_each_4p(Q start, Q end, void(*f)(U)) {
        auto start1 = start;
        auto start2 = ++start1;
        auto start3 = ++start2;
        ++start3;
        auto l_f = [](Q start, Q end, void(*f)(U)) {
            while (start != end) {
                f(*start);
                for (int i = 0; i < 4; ++i) {
                    ++start;
                    if (start == end)
                        break;
                }
            }
            };
        auto fut1 = std::async(std::launch::async, l_f, start, end, f);
        auto fut2 = std::async(std::launch::async, l_f, start1, end, f);
        auto fut3 = std::async(std::launch::async, l_f, start2, end, f);
        auto fut4 = std::async(std::launch::async, l_f, start3, end, f);
    }
}


namespace gdp {
    template<class Q, class U>
    void for_each_recur_4p(Q start, Q end, void(*f)(U)) {
        int size_potok = 4;//  колличеству потоков прив€зыватьс€ не стал и так дольше работает чем ћаин 4 достаточно. 
        static int x = size_potok;
        auto start1 = start;
        //int z = x;//ƒл€ проверки 
        auto fut = std::async(std::launch::async, [&]() {
            while (start != end) {
                //std::cout << z<<" ";//что все потоки работают
                f(*start);
                for (int i = 0; i < size_potok; ++i) {
                    ++start;
                    if (start == end)
                        break;
                }
            }
            });
        if (--x == 0)
            return;
        for_each_recur_4p(++start1, end, f);
    }
}

int main() {
    int kol_vo = 1000000;
    {
        std::list<int> v(kol_vo, 2);
        auto start = std::chrono::steady_clock::now();
        gdp::for_each_main(v.begin(), v.end(), foo);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        Y1 std::cout << "Main potok time            : "; G1  std::cout << elapsed_seconds.count() << "s\n"; W1
    }
    {
        std::list<int> v(kol_vo, 2);
        auto start = std::chrono::steady_clock::now();
        gdp::for_each_4p(v.begin(), v.end(), foo);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        Y1 std::cout << "Bez recursii 4 potoka time : "; G1  std::cout << elapsed_seconds.count() << "s\n"; W1
    }
    {
        std::list<int> v(kol_vo, 2);
        auto start = std::chrono::steady_clock::now();
        gdp::for_each_recur_4p(v.begin(), v.end(), foo);
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        Y1 std::cout << "Recursiya 4 potoka time    : "; G1  std::cout << elapsed_seconds.count() << "s\n"; W1
    }
    /*for (auto x : v1)
        std::cout << x << " ";
    std::cout << "\n ";*/
}

