//COUNTER. Program increases/decreases/outputs counter by request.

#include "counter.h"
#include <iostream>

int main(int argc, char** argv) {
	Counter counter;

	std::string answer = getAnswer();
	setScore(counter, answer);
	manageScore(&counter);

	std::cout << "\n*** PROGRAM CLOSED ***\n";
	return 0;
}