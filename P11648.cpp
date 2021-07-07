#include <cmath>
#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int step = 0;
	while (n >= 10) {
		int next = 1;
		std::div_t div{ n };
		do {
			div = std::div(div.quot, 10);
			next *= div.rem;
		} while (div.quot);

		n = next;
		++step;
	}

	std::cout << step;
}