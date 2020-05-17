#include <iostream>

int main() {
	double n;
	std::cin >> n;

	int d = 1;
	while ((n - 2) / 6 >= 0) {
		n -= 6 * d;
		++d;
	}

	std::cout << d;
}