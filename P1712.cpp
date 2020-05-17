#include <cmath>
#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;

	const double point = std::floor(-static_cast<double>(a) / -(c - b));
	std::cout << static_cast<int>(point >= 0 ? point + 1 : -1);
}