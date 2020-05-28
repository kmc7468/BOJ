#include <ios>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int s, n;
		std::cin >> s >> n;

		int result = s;
		for (int j = 0; j < n; ++j) {
			int q, p;
			std::cin >> q >> p;
			result += q * p;
		}
		std::cout << result << '\n';
	}
}