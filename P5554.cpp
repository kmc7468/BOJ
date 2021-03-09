#include <cmath>
#include <iostream>

int main() {
	int sum = 0;
	for (int i = 0; i < 4; ++i) {
		int s;
		std::cin >> s;
		sum += s;
	}

	const std::div_t div = std::div(sum, 60);
	std::cout << div.quot << '\n' << div.rem;
}