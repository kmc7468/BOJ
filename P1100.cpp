#include <iostream>

int main() {
	int result = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			char c;
			std::cin >> c;

			if ((j + i % 2) % 2 == 0 && c == 'F') {
				++result;
			}
		}
		std::cin.ignore();
	}
	std::cout << result;
}