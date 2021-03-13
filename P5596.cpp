#include <iostream>

int main() {
	int sum[2] = { 0 };
	for (int i = 0; i < 8; ++i) {
		int score;
		std::cin >> score;
		sum[i / 4] += score;
	}

	std::cout << (sum[0] >= sum[1] ? sum[0] : sum[1]);
}