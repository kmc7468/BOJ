#include <iostream>

int main() {
	int n, t, c, p;
	std::cin >> n >> t >> c >> p;
	std::cout << (n - 1) / t * c * p;
}