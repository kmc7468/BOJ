#include <cmath>
#include <iostream>

int main() {
	int m, n;
	std::cin >> m >> n;

	int min = 0, sum = 0;
	for (int i = m; i <= n; ++i) {
		double intPart;
		if (std::modf(std::sqrt(i), &intPart) == 0) {
			sum += i;
			if (!min) {
				min = i;
			}
		}
	}

	if (sum == 0) {
		std::cout << -1;
	} else {
		std::cout << sum << '\n' << min;
	}
}