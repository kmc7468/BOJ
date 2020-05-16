#include <iostream>
#include <string>

int main() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		int r;
		std::cin >> r;

		std::string string;
		std::cin >> string;

		for (const char c : string) {
			for (int i = 0; i < r; ++i) {
				std::cout << c;
			}
		}
		std::cout << '\n';
	}
}