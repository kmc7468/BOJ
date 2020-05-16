#include <algorithm>
#include <iostream>

int main() {
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		int score;
		std::cin >> score;
		sum += std::max(score, 40);
	}
	std::cout << sum / 5;
}