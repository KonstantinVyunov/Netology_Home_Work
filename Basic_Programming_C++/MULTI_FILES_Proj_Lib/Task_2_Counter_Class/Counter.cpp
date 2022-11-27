// Class COUNTER - LOGIC

#include "counter.h"

Counter::Counter() {
	this->score = 1;
}
Counter::Counter(int score) {
	this->score = score;
}
void Counter::increasScore() {
	++this->score;
	return;
}
void Counter::decreasScore() {
	--this->score;
	return;
}
int Counter::getScore() {
	return this->score;
}