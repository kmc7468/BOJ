#include <iostream>

int main() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n - i; ++j) {
			std::cout << ' ';
		}
		for (int j = 0; j < 2 * i - 1; ++j) {
			std::cout << '*';
		}
		std::cout << '\n';
	}
}