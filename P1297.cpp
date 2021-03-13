#include <cmath>
#include <iostream>

int main() {
	int x, hr, wr;
	std::cin >> x >> hr >> wr;

	const double k = x / std::sqrt(hr * hr + wr * wr);
	std::cout << static_cast<int>(k * hr) << ' ' << static_cast<int>(k * wr);
}