#include <ios>
#include <iostream>
#include <queue>
#include <utility>

int g_Map[1'000][1'000];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::queue<std::pair<int, int>> queue;
	int zeroCount = 0, oneCount = 0;

	int m, n;
	std::cin >> m >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> g_Map[i][j];
			if (g_Map[i][j] == 0) {
				++zeroCount;
			} else if (g_Map[i][j] == 1) {
				queue.push({ i, j });
				++oneCount;
			}
		}
	}

	int day = 0;
	while (!queue.empty()) {
		if (oneCount == 0) {
			oneCount = static_cast<int>(queue.size());
			++day;
		}

		const auto [y, x] = queue.front();
		queue.pop();
		--oneCount;

		if (x != 0 && g_Map[y][x - 1] == 0) {
			g_Map[y][x - 1] = 1;
			--zeroCount;
			queue.push({ y, x - 1 });
		}
		if (x != m - 1 && g_Map[y][x + 1] == 0) {
			g_Map[y][x + 1] = 1;
			--zeroCount;
			queue.push({ y, x + 1 });
		}
		if (y != 0 && g_Map[y - 1][x] == 0) {
			g_Map[y - 1][x] = 1;
			--zeroCount;
			queue.push({ y - 1, x });
		}
		if (y != n - 1 && g_Map[y + 1][x] == 0) {
			g_Map[y + 1][x] = 1;
			--zeroCount;
			queue.push({ y + 1, x });
		}
	}

	std::cout << (zeroCount ? -1 : day);
}