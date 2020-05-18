#include <iostream>
#include <numeric>

int main() {
	int n, m;
	char dummy;
	std::cin >> n >> dummy >> m;

	const int gcd = std::gcd(n, m);
	std::cout << n / gcd << ':' << m / gcd;
}