#include <algorithm>
#include <cmath>
#include <iostream>

int main() {
	while (true) {
		int lengths[3];
		for (int& length : lengths) {
			std::cin >> length;
		}

		static constexpr int zeros[] = { 0, 0, 0 };
		if (std::equal(lengths, lengths + 3, zeros)) break;

		std::sort(lengths, lengths + 3);
		std::cout << (std::pow(lengths[2], 2) == std::pow(lengths[0], 2) + std::pow(lengths[1], 2) ? "right\n" : "wrong\n");
	}
}