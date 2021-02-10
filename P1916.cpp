#include <algorithm>
#include <ios>
#include <iostream>
#include <numeric>

int g_Cost[1'000 + 1][1'000 + 1];
int g_Cheapest[1'000 + 1];
int g_IsVisited[1'000 + 1];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::fill_n(g_Cheapest + 1, n, std::numeric_limits<int>::max());

	int m, connected = 0;
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int from, to, cost;
		std::cin >> from >> to >> cost;

		if (g_Cost[from][to] == 0 || g_Cost[from][to] > cost + 1) {
			if (g_IsVisited[to] == 0) {
				g_IsVisited[to] = 1;
				++connected;
			}
			g_Cost[from][to] = cost + 1;
		}
	}

	int from, to;
	std::cin >> from >> to;
	g_Cheapest[from] = 0;
	g_IsVisited[from] = 2;

	int current = from;
	while (connected != 0) {
		for (int i = 1; i <= n; ++i) {
			if (g_IsVisited[i] != 1 || g_Cost[current][i] == 0) continue;

			g_Cheapest[i] = std::min(g_Cheapest[i], g_Cheapest[current] + (g_Cost[current][i] - 1));
		}

		g_IsVisited[current] = 2;
		--connected;

		int* localCheapest = nullptr;
		for (int i = 1; i <= n; ++i) {
			if (g_IsVisited[i] != 1) continue;

			if (localCheapest == nullptr || *localCheapest > g_Cheapest[i]) {
				localCheapest = g_Cheapest + i;
			}
		}
		current = std::distance(g_Cheapest, localCheapest);
	}

	std::cout << g_Cheapest[to];
}