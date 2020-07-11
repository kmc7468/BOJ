#include <cmath>
#include <iostream>

int main() {
	while (true) {
		int b, n;
		std::cin >> b >> n;
		if (!b && !n) break;

		const double root = std::pow(b, 1. / n);
		const int down = static_cast<int>(std::floor(root));
		const int up = static_cast<int>(std::ceil(root));

		const int downDiff = std::abs(std::pow(down, n) - b);
		const int upDiff = std::abs(std::pow(up, n) - b);
		std::cout << (downDiff < upDiff ? down : up) << '\n';
	}
}