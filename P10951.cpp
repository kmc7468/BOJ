#include <iostream>

int main() {
	while (true) {
		int a, b;
		std::cin >> a >> b;
		if (std::cin.eof()) break;
		std::cout << a + b << '\n';
	}
}