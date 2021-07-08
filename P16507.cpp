#include <ios>
#include <iostream>

int g_Sum[1001][1001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int r, c, q;
	std::cin >> r >> c >> q;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			int pixel;
			std::cin >> pixel;
			g_Sum[i][j] = g_Sum[i - 1][j] + g_Sum[i][j - 1] - g_Sum[i - 1][j - 1] + pixel;
		}
	}

	for (int i = 0; i < q; ++i) {
		int r1, c1, r2, c2;
		std::cin >> r1 >> c1 >> r2 >> c2;
		std::cout << (g_Sum[r2][c2] - g_Sum[r2][c1 - 1] - g_Sum[r1 - 1][c2] + g_Sum[r1 - 1][c1 - 1]) / ((r2 - r1 + 1) * (c2 - c1 + 1)) << '\n';
	}
}