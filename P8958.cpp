#include <iostream>
#include <string>

int main() {
	int n;
	std::cin >> n;
	std::cin.get();
	for (int i = 0; i < n; ++i) {
		std::string result;
		std::getline(std::cin, result);

		int score = 0;
		int delta = 1;
		for (const char c : result) {
			if (c == 'O') {
				score += delta++;
			} else {
				delta = 1;
			}
		}

		std::cout << score << '\n';
	}
}