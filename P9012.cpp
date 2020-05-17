#include <iostream>
#include <string>

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::string string;
		std::cin >> string;

		int depth = 0;
		for (const char c : string) {
			if (c == '(') {
				++depth;
			} else {
				--depth;
				if (depth < 0) break;
			}
		}

		if (depth == 0) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}