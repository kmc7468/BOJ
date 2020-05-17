#include <cmath>
#include <iostream>

int main() {
	double n;
	std::cin >> n;
	std::cout << std::ceil((-3 + std::sqrt(9 + 12 * (n - 1))) / 6 + 1);
}