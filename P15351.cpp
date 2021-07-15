#include <ios>
#include <iostream>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::cin.ignore();

	for (int i = 0; i < n; ++i) {
		std::string hobby;
		std::getline(std::cin, hobby);

		int score = 0;
		for (char c : hobby) {
			score += (c == ' ' ? 0 : c - 'A' + 1);
		}

		if (score == 100) {
			std::cout << "PERFECT LIFE\n";
		} else {
			std::cout << score << '\n';
		}
	}
}