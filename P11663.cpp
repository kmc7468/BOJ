#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> points(n);
	for (int& point : points) {
		std::cin >> point;
	}
	std::sort(points.begin(), points.end());

	for (int i = 0; i < m; ++i) {
		int from, to;
		std::cin >> from >> to;

		const auto a = std::lower_bound(points.begin(), points.end(), from);
		auto b = std::upper_bound(points.begin(), points.end(), to);
		if (b != points.begin()) {
			--b;
		} else {
			b = points.end();
		}
		std::cout << (a == points.end() || b == points.end() ? 0 : std::distance(a, b) + 1) << '\n';
	}
}