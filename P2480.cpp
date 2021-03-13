#include <algorithm>
#include <iostream>

int main() {
	int score[3];
	for (int& s : score) {
		std::cin >> s;
	}
	std::sort(score, score + 3);

	if (score[0] == score[2]) {
		std::cout << 1000 * (score[0] + 10);
	} else if (score[0] == score[1] || score[1] == score[2]) {
		std::cout << 100 * (score[1] + 10);
	} else {
		std::cout << 100 * score[2];
	}
}