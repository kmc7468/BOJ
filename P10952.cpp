#include <iostream>

int main() {
	while (true) {
		int a, b;
		std::cin >> a >> b;
		if (!a && !b) break;
		std::cout << a + b << '\n';
	}
}