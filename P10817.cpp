#include <algorithm>
#include <iostream>

int main() {
	int arr[3];
	for (int i = 0; i < 3; ++i) {
		std::cin >> arr[i];
	}
	std::sort(arr, arr + 3);
	std::cout << arr[1];
}