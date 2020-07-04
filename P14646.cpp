#include <ios>
#include <iostream>

bool g_HasStickers[100000];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	int stickers = 0, max = 0;
	for (int i = 0; i < 2 * n; ++i) {
		int m;
		std::cin >> m;

		if (g_HasStickers[m - 1] = !g_HasStickers[m - 1]) {
			if (++stickers > max) {
				max = stickers;
			}
		} else {
			--stickers;
		}
	}

	std::cout << max;
}