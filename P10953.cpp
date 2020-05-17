#include <iostream>

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		char dummy;
		std::cin >> a >> dummy >> b;
		std::cout << a + b << '\n';
	}
}