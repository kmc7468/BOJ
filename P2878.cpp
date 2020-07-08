#include <algorithm>
#include <functional>
#include <ios>
#include <iostream>

int g_Requireds[100000];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int m, n;
	std::cin >> m >> n;

	int requiredSum = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> g_Requireds[i];
		requiredSum += g_Requireds[i];
	}
	std::sort(g_Requireds, g_Requireds + n, std::greater<int>());

	int end = 1;
	while (m) {
		while (end < n && g_Requireds[end] == g_Requireds[end - 1]) ++end;

		int diff = g_Requireds[end - 1];
		if (end < n) {
			diff -= g_Requireds[end];
		}

		const int given = std::max(1, std::min(m / end, diff));
		for (int i = 0; i < end && m > 0; ++i) {
			g_Requireds[i] -= given;
			m -= given;
		}
	}

	unsigned long long angry = 0;
	for (int i = 0; i < n; ++i) {
		angry += static_cast<unsigned long long>(g_Requireds[i]) * g_Requireds[i];
	}
	std::cout << angry;
}