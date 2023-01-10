// Time - O(log2n) ; Memory - O(n)

#include <iostream>

int function(int* array, int point, int array_length) {
	int first_index = 0;
	int last_index = (array_length - 1);
	int middle_index = last_index / 2;
	
	while (array[middle_index] != point) {
		if (array[middle_index] > point) {
			last_index = (middle_index - 1);
			middle_index = (first_index + last_index) / 2;
		} else if (array[middle_index] < point) {
			first_index = (middle_index + 1);
			middle_index = (first_index + last_index) / 2;
		}
	}

	int answer = ((array_length - 1) - middle_index);

	return answer;
}

int main(int argc, char** argv) {

	int point = 0;
	std::cout << "Enter the num in between 1 to 10: ";
	std::cin >> point;
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::cout << "Qty of nums in the array following by " << point << ": " << function(array, point, (sizeof(array) / sizeof(array[0]))) << std::endl;

	return 0;
}