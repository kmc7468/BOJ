#include <iostream>

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			std::cout << ' ';
		}
		std::cout << '*';
		for (int j = 0; j < 2 * (i - 1) - 1; ++j) {
			std::cout << ' ';
		}
		if (i > 1) {
			std::cout << '*';
		}
		std::cout << '\n';
	}
	for (int i = 0; i < 2 * n - 1; ++i) {
		std::cout << '*';
	}
}