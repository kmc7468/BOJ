#include <iostream>

char g_Map[397][399];

void Star(int n, int baseX, int baseY);

int main() {
	int n;
	std::cin >> n;

	if (n == 1) {
		std::cout << "*";
		return 0;
	}
	Star(n, 0, 0);

	const int width = 1 + 4 * (n - 1);
	const int height = n * 4 - 1;
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			const char value = g_Map[x][y];
			std::cout << (value ? value : ' ');
			if (y == 1) break;
		}
		std::cout << '\n';
	}
}

void Star(int n, int baseX, int baseY) {
	if (n == 1) {
		g_Map[baseX][baseY] = g_Map[baseX + 1][baseY]
			= g_Map[baseX][baseY + 1]
			= g_Map[baseX][baseY + 2] = '*';
		return;
	}

	const int width = 1 + 4 * (n - 1);
	const int height = n * 4 - 1;
	for (int i = 0; i < width; ++i) {
		g_Map[baseX + i][baseY] = g_Map[baseX + i][baseY + height - 1] = '*';
	}
	for (int i = 0; i < height - 2; ++i) {
		g_Map[baseX][baseY + i + 1] = g_Map[baseX + width - 1][baseY + i + 1] = '*';
	}
	g_Map[baseX + width - 1][baseY + 1] = 0;
	if (baseX) {
		g_Map[baseX + width][baseY] = '*';
	}

	Star(n - 1, baseX + 2, baseY + 2);
}