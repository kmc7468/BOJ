#include <iostream>

char g_Map[6143][3072];

void Star(int n, int baseX, int baseY);

int main() {
	int n;
	std::cin >> n;

	const int width = 2 * n - 1;
	Star(n, width / 2, 0);

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < 2 * n - 1; ++x) {
			const char value = g_Map[x][y];
			std::cout << (value ? value : ' ');
		}
		std::cout << '\n';
	}
}

void Star(int n, int baseX, int baseY) {
	if (n == 3) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j <= 2 * i; ++j) {
				if (i == 1 && j == 1) continue;
				g_Map[baseX - i + j][baseY + i] = '*';
			}
		}
		return;
	}

	const int blockWidth = n / 2;
	Star(blockWidth, baseX, baseY);
	Star(blockWidth, baseX - blockWidth, baseY + blockWidth);
	Star(blockWidth, baseX + blockWidth, baseY + blockWidth);
}