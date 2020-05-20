#include <algorithm>
#include <iostream>

int g_Temps[100];
int g_Sums[100];

int main() {
	int n, k;
	std::cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		std::cin >> g_Temps[i];
		if (i < k) {
			g_Sums[0] += g_Temps[i];
		}
	}

	for (int i = 1; i < n - k + 1; ++i) {
		g_Sums[i] = g_Sums[i - 1] - g_Temps[i - 1] + g_Temps[i + k - 1];
	}
	std::cout << *std::max_element(g_Sums, g_Sums + n - k + 1);
}