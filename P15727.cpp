#include <cmath>
#include <iostream>

int main() {
	int l;
	std::cin >> l;

	const std::div_t div = std::div(l, 5);
	std::cout << div.quot + !!div.rem;
}