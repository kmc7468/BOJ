#include <cmath>
#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;

	int m = a * b * c;
	int table[10]{ 0 };
	while (m) {
		const std::div_t div = std::div(m, 10);
		++table[div.rem];
		m = div.quot;
	}

	for (const int c : table) {
		std::cout << c << '\n';
	}
}