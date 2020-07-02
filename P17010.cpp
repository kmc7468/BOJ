#include <iostream>

int main() {
	int l;
	std::cin >> l;
	for (int i = 0; i < l; ++i) {
		int s;
		char c;
		std::cin >> s >> c;
		for (int j = 0; j < s; ++j) {
			std::cout << c;
		}
		std::cout << '\n';
	}
}