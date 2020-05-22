#include <iostream>

int main() {
	while (true) {
		int n;
		std::cin >> n;
		if (std::cin.eof()) break;

		int k = 1;
		for (int i = 1; ; ++i) {
			const int remainder = k % n;
			if (remainder == 0) {
				std::cout << i << '\n';
				break;
			}
			k = remainder * 10 + 1;
		}
	}
}