#include <cmath>
#include <iostream>

int main() {
	int m, n;
	std::cin >> m >> n;

	const std::div_t md = std::div(m - 1, 4), nd = std::div(n - 1, 4);
	std::cout << std::abs(md.quot - nd.quot) + std::abs(md.rem - nd.rem);
}