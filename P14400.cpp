#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>

int g_Xs[100000], g_Ys[100000];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> g_Xs[i] >> g_Ys[i];
	}
	std::sort(g_Xs, g_Xs + n);
	std::sort(g_Ys, g_Ys + n);

	const int x = g_Xs[n / 2], y = g_Ys[n / 2];

	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += std::abs(g_Xs[i] - x);
		sum += std::abs(g_Ys[i] - y);
	}
	std::cout << sum;
}