#include <iostream>

char g_Map[2187][2187];

void Star(int n, int baseX, int baseY);

int main() {
	int n;
	std::cin >> n;
	Star(n, 0, 0);

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
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

	const int blockWidth = n / 3;
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; x < 3; ++x) {
			if (x == 1 && y == 1) continue;
			Star(blockWidth, baseX + x * blockWidth, baseY + y * blockWidth);
		}
	}
}