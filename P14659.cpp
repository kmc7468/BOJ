#include <ios>
#include <iostream>

int g_Heights[30'000];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> g_Heights[i];
	}

	int base = g_Heights[0], max = 0, cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (i != n && g_Heights[i] < base) {
			++cur;
		} else {
			if (i != n) {
				base = g_Heights[i];
			}
			if (max < cur) {
				max = cur;
			}
			cur = 0;
		}
	}
	std::cout << max;
}