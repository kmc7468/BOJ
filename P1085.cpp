#include <algorithm>
#include <cmath>
#include <iostream>

int main() {
	int x, y, w, h;
	std::cin >> x >> y >> w >> h;

	const int distances[] = {
		std::abs(x), std::abs(w - x), std::abs(y), std::abs(h - y)
	};
	std::cout << *std::min_element(distances, distances + 4);
}