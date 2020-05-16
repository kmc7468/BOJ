#include <iostream>

int main() {
	std::cin.tie(nullptr);
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i) {
		int a, b;
		std::cin >> a >> b;
		std::cout << a + b << '\n';
	}
}