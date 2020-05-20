#include <algorithm>
#include <iostream>
#include <limits>

int g_Sums[101];

int main() {
	int n, k;
	std::cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		int temp;
		std::cin >> temp;
		g_Sums[i + 1] = g_Sums[i] + temp;
	}

	int max = std::numeric_limits<int>::min();
	for (int i = 0; i < n - k + 1; ++i) {
		const int sum = g_Sums[i + k] - g_Sums[i];
		if (max < sum) {
			max = sum;
		}
	}

	std::cout << max;
}