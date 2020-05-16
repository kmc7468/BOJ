#include <cmath>
#include <iostream>
#include <limits>

int main() {
	int kg;
	std::cin >> kg;

	int min = std::numeric_limits<int>::max();
	for (int i = 0; i <= kg / 5; ++i) {
		const std::div_t three = std::div(kg - 5 * i, 3);
		if (three.rem) continue;
		const int need = i + three.quot;
		if (min > need) {
			min = need;
		}
	}

	std::cout << (min == std::numeric_limits<int>::max() ? -1 : min);
}