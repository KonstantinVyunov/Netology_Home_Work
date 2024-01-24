#include <iostream>

void print_arr(int* arr, int arr_lenght) {
	for (int i = 0; i < arr_lenght; ++i) {
		if (i < arr_lenght - 1) {
			std::cout << arr[i] << ", ";
		}
		else {
			std::cout << arr[i] << '.';
		}

	}
}

// не работает. не смог разобраться.
void merge_sort(int* arr, const int arr_lenght) {
	if (arr_lenght == 1) {
		return;
	} else {
		int* arr_left = new int[arr_lenght / 2];
		int* arr_right = new int[arr_lenght - (arr_lenght / 2)];
		int index_left = 0, index_right = 0, index_arr = 0;

		for (int i = 0; i < arr_lenght; ++i) {
			if (i < arr_lenght / 2) {
				arr_left[i] = arr[i];
			} else {
				arr_right[i - (arr_lenght / 2)] = arr[i];
			}
		}
		
		while (index_left < (arr_lenght / 2) || index_right < (arr_lenght - (arr_lenght / 2))) {
			if (index_left == arr_lenght / 2) {
				arr[index_arr] = arr_right[index_right];
				++index_right;
			} else if (index_right == (arr_lenght - (arr_lenght / 2))) {
				arr[index_arr] = arr_left[index_left];
				++index_left;
			} else {
				if (arr_left[index_left] <= arr_right[index_right]) {
					arr[index_arr] = arr_left[index_left];
					++index_left;
				} else {
					arr[index_arr] = arr_right[index_right];
					++index_right;
				}
			}
			++index_arr;
		}
		delete[] arr_left, arr_right;
	}
	return;
}

void sort(int* arr, const int arr_lenght) {
	if (arr_lenght == 1) {
		return;
	} else {
		
	}
	return;
}

int main(int argc, char** argv) {
	
	int arr[6] = { 3, 18, 43, 0, 2, 11};
	//int arr[11] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33, 1};
	//int arr[15] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
	//int arr[18] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
	int arr_lenght = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Initial array:\t";
	print_arr(arr, arr_lenght);
	std::cout << std::endl;
	merge_sort(arr, arr_lenght);
	std::cout << "Sorted array:\t";
	print_arr(arr, arr_lenght);
	
	return 0;
}