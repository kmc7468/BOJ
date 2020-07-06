#include <cmath>
#include <iostream>

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; ; ++i) {
		const double boundary = std::pow(10, i);
		if (boundary < n) {
			n = static_cast<int>(std::round(n / boundary) * boundary);
		} else break;
	}
	std::cout << n;
}