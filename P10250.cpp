#include <cmath>
#include <ios>
#include <iomanip>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int h, w, n;
		std::cin >> h >> w >> n;

		const std::div_t div = std::div(n - 1, h);
		std::cout << div.rem + 1 << std::setfill('0') << std::setw(2) << div.quot + 1 << '\n';
	}
}