// Class COUNTER - HEADER

#pragma once
#include <iostream>

class Counter {
private:
	int score;
public:
	Counter();
	Counter(int score);

	void increasScore();
	void decreasScore();
	int getScore();
};

std::string toLowerCase(std::string& answer);
std::string getAnswer();
void setScore(Counter& counter, std::string& answer);
void manageScore(Counter* counter);