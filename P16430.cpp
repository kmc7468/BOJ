#include <iostream>
#include <numeric>

int main() {
	int a, b;
	std::cin >> a >> b;

	const int p = b - a, gcd = std::gcd(p, b);
	std::cout << p / gcd << ' ' << b / gcd;
}