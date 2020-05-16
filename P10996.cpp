#include <iostream>

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n * 2; ++i) {
		for (int j = !(i & 1); j < n + !(i & 1); ++j) {
			std::cout << (j & 1 ? ' ' : '*');
		}
		std::cout << '\n';
	}
}