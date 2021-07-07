#include <ios>
#include <iostream>
#include <map>
#include <vector>

using Point = std::map<int, int>;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> axis;
	for (int i = 0; i < m; ++i) {
		std::cin >> axis.emplace_back();
	}
	std::cin.ignore();

	std::vector<Point> points{ { { 0, 0 } } };
	for (int i = 0; i < m; ++i) {
		char move;
		std::cin >> move;

		Point newPoint = points.back();
		newPoint[axis[i]] += (move == '+' ? 1 : -1);
		for (int j = 0; j < i; ++j) {
			for (const auto& [axis, value] : newPoint) {
				if (points[j][axis] != value) goto valid;
			}

			std::cout << 0;
			return 0;

		valid:;
		}

		points.push_back(newPoint);
	}

	std::cout << 1;
}