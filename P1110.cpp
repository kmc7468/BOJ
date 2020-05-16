#include <iostream>

int main() {
	int n, m, k = 0;
	std::cin >> n;
	m = n;
	do {
		++k;
		m = (m % 10 * 10 + (m / 10 + m % 10) % 10);
	} while (n != m);
	std::cout << k;
}