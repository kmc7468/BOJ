#include <cmath>
#include <iostream>

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;

	const std::div_t div = std::div(k, m);
	std::cout << div.quot << ' ' << div.rem;
}