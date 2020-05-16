#include <iostream>

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int a, b;
		std::cin >> a >> b;
		std::cout << "Case #" << i + 1 << ": " << a + b << '\n';
	}
}