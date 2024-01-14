#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

int main() {
    std::string s{ "Hello world!!" };
    std::cout << "[IN]: " << s << std::endl;
    std::map<char, int> m;
    for (auto s : s)
        ++m[s];
    std::vector<std::pair<char, int>>vec;
    for (auto x : m)
        vec.push_back(x);
    std::sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
        return a.second > b.second;
        });
    std::cout << "[OUT]:" << std::endl;
    for (const auto& elem : vec)
        std::cout << elem.first << ": " << elem.second << std::endl;
}

