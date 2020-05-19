#include <cmath>
#include <iostream>

int Index(int n, int r, int c);

int main() {
	int n, r, c;
	std::cin >> n >> r >> c;
	std::cout << Index(std::pow(2, n), r, c);
}

int Index(int n, int r, int c) {
	if (n == 2) return r * 2 + c;

	const int blockWidth = n / 2;
	const int blockArea = blockWidth * blockWidth;
	return Index(blockWidth, r % blockWidth, c % blockWidth) + blockArea * Index(2, r / blockWidth, c / blockWidth);
}