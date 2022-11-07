#include <iostream>
#include <fstream>

int** readFile(int& length_1, int& length_2) {
	int** array = nullptr;
	int arr_length[2] = { 0, 0 };
	std::ifstream file("input.txt");
	if (!file.is_open()) {
		std::cout << "No \"input.txt\" file found!";
	}
	else {
		array = new int* [2];
		for (int i = 0; i < 2; ++i) {
			file >> arr_length[i];
			array[i] = new int[arr_length[i]];
			for (int j = 0; j < arr_length[i]; ++j) {
				file >> array[i][j];
			}
		}
	}
	length_1 = arr_length[0];
	length_2 = arr_length[1];
	file.close();
	return array;
}

void shiftElements(int** array, int length_1, int length_2) {
	int num_1 = array[0][0];
	int num_2 = array[1][length_2 - 1];
	for (int i = 0; i < length_1; ++i) {
		if (i == length_1 - 1) {
			array[0][i] = num_1;
		}
		else {
			array[0][i] = array[0][i + 1];
		}
	}
	for (int j = (length_2 - 1); j >= 0; --j) {
		if (j == 0) {
			array[1][0] = num_2;
		}
		else {
			array[1][j] = array[1][j - 1];
		}
	}
	return;
}

void writeFile(int** array, int length_1, int length_2) {
	std::ofstream file("output.txt");
	int arr_length[2] = { length_1, length_2 };
	for (int i = 1; i >= 0; --i) {
		file << arr_length[i] << '\n';
		for (int j = 0; j < arr_length[i]; ++j) {
			file << array[i][j] << ' ';
		}
		file << std::endl;
	}
	file.close();
	return;
}

void cleanMemory(int** array) {
	for (int i = 0; i < 2; ++i) {
		delete[] array[i];
	}
	delete[] array;
	return;
}

int main(int argc, char** argv) {
	int length_1, length_2;
	int** array = readFile(length_1, length_2);

	shiftElements(array, length_1, length_2);

	writeFile(array, length_1, length_2);

	cleanMemory(array);

	return 0;
}