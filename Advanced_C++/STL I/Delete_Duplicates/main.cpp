#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>

int main(int argc, char** argv) {
    std::string figure, line = { "6 1 5 1 3 4 4" };

    std::stringstream in_flow(line);
    size_t size = 0;
    in_flow >> size;
    std::cout << "Initial size: " << size << std::endl;
    std::vector<int> i_vect{};
    while (getline(in_flow, figure, ' ')) {
        int num;
        in_flow >> num;
        i_vect.push_back(num);
    }

    std::cout << " [IN]: ";
    for (auto i = i_vect.begin(); i != i_vect.end(); ++i) {
        std::cout << *i << ' ';
    }

    std::sort(i_vect.begin(), i_vect.end(), [](const auto& lhs, const auto& rhs) {return lhs > rhs; });
    auto last = std::unique(i_vect.begin(), i_vect.end());
    i_vect.erase(last, i_vect.end());
    std::cout << std::endl;;

    std::cout << "[OUT]: ";
    for (auto i = i_vect.begin(); i != i_vect.end(); ++i) {
        std::cout << *i << ' ';
    }

	return EXIT_SUCCESS;
}