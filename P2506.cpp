#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int score = 0, delta = 0;
	for (int i = 0; i < n; ++i) {
		int result;
		std::cin >> result;
		score += result ? ++delta : delta = 0;
	}

	std::cout << score;
}