#include <iostream>

int main() {
	int l, p, answer;
	std::cin >> l >> p;
	answer = l * p;

	for (int i = 0; i < 5; ++i) {
		int news;
		std::cin >> news;
		std::cout << news - answer << ' ';
	}
}