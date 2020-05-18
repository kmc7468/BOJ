#include <cmath>
#include <iostream>

bool DoubleEqual(double a, double b);

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int x1, y1, r1, x2, y2, r2;
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		const double d = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
		const int rSum = r1 + r2;
		const int rDiff = std::abs(r1 - r2);

		if (rDiff == 0 && d == 0) {
			std::cout << -1 << '\n';
		} else if (DoubleEqual(rSum, d) || DoubleEqual(rDiff, d)) {
			std::cout << 1 << '\n';
		} else if (rDiff < d && d < rSum) {
			std::cout << 2 << '\n';
		} else {
			std::cout << 0 << '\n';
		}
	}
}

bool DoubleEqual(double a, double b) {
	return std::fabs(a - b) < 0.000001;
}