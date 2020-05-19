#include <iostream>

int main() {
	unsigned n;
	std::cin >> n;
	std::cout << ((n & (n - 1)) == 0);
}