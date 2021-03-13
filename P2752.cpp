#include <algorithm>
#include <iostream>

int main() {
	int numbers[3];
	for (int& n : numbers) {
		std::cin >> n;
	}
	std::sort(numbers, numbers + 3);

	for (int n : numbers) {
		std::cout << n << ' ';
	}
}