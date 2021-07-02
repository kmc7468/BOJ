#include <algorithm>
#include <ios>
#include <iostream>

int g_Matrix[1024][1024];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> g_Matrix[i][j];
		}
	}

	while (n > 1) {
		for (int i = 0; i < n / 2; ++i) {
			for (int j = 0; j < n / 2; ++j) {
				int array[4] = {
					g_Matrix[2 * i][2 * j], g_Matrix[2 * i + 1][2 * j],
					g_Matrix[2 * i][2 * j + 1], g_Matrix[2 * i + 1][2 * j + 1]
				};
				std::sort(array, array + 4);

				g_Matrix[i][j] = array[2];
			}
		}
		n >>= 1;
	}

	std::cout << g_Matrix[0][0];
}