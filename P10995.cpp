#include <iostream>

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = !(i & 1); j < 2 * n + !(i & 1); ++j) {
			std::cout << (j & 1 ? ' ' : '*');
		}
		std::cout << '\n';
	}
}