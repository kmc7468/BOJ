#include <algorithm>
#include <ios>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int a, b, s;
		std::cin >> a >> b >> s;

		bool swaped = false;
		if (a < b) {
			std::swap(a, b);
			swaped = true;
		}

		bool impossible = true;
		for (int j = s / a; j >= 0; --j) {
			const int r = s - j * a;
			if (r % b == 0) {
				if (swaped) {
					std::cout << r / b << ' ' << j << '\n';
				} else {
					std::cout << j << ' ' << r / b << '\n';
				}
				impossible = false;
				break;
			}
		}

		if (impossible) {
			std::cout << "Impossible\n";
		}
	}
}