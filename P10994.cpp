#include <iostream>

char g_Map[397][397];

void Star(int n, int baseX, int baseY);

int main() {
	int n;
	std::cin >> n;

	const int width = 1 + 4 * (n - 1);
	Star(width, 0, 0);

	for (int y = 0; y < width; ++y) {
		for (int x = 0; x < width; ++x) {
			const char value = g_Map[x][y];
			std::cout << (value ? value : ' ');
		}
		std::cout << '\n';
	}
}

void Star(int n, int baseX, int baseY) {
	if (n == 1) {
		g_Map[baseX][baseY] = '*';
		return;
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (y == 0 || y == n - 1 || x == 0 || x == n - 1) {
				g_Map[baseX + x][baseY + y] = '*';
			}
		}
	}
	Star(n - 4, baseX + 2, baseY + 2);
}