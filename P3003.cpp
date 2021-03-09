#include <iostream>

int main() {
	static constexpr int original[] = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < 6; ++i) {
		int number;
		std::cin >> number;
		std::cout << original[i] - number << ' ';
	}
}