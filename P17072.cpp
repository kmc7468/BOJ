#include <algorithm>
#include <ios>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int r, g, b;
			std::cin >> r >> g >> b;

			static constexpr char mappings[] = { '#', 'o', '+', '-', '.' };
			std::cout << mappings[std::min((2126 * r + 7152 * g + 722 * b) / 510000, 4)];
		}
		std::cout << '\n';
	}
}