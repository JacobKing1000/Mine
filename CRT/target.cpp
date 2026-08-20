
#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == target) return i;
	}
	return -1;
}

int main() {
	const int SIZE = 5;
	int arr[SIZE 6];
	int target;

	// read target
	if (!(cin >> target)) return 0;

	for (int i = 0; i < SIZE; ++i) { 
		if (!(cin >> arr[i])) return 0;
	}

	int idx = linearSearch(arr, SIZE, target);
	cout << idx;
	return 0;
}
