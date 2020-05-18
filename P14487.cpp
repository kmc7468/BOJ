#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int sum = 0, max = 0;
	for (int i = 0; i < n; ++i) {
		int cost;
		std::cin >> cost;
		sum += cost;
		if (cost > max) {
			max = cost;
		}
	}
	std::cout << sum - max;
}