#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int max = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		int score;
		std::cin >> score;
		sum += score;
		if (max < score) {
			max = score;
		}
	}

	std::cout << 100. / max * sum / n;
}