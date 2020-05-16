#include <iostream>
#include <limits>

int main() {
	int n, min = std::numeric_limits<int>::max(), max = std::numeric_limits<int>::min();
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		if (v < min) {
			min = v;
		}
		if (v > max) {
			max = v;
		}
	}
	std::cout << min << ' ' << max;
}