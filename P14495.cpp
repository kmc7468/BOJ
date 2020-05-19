#include <iostream>

long long g_FiboSimilar[117]{ 0, 1, 1, 1 };

int main() {
	int n;
	std::cin >> n;

	for (int i = 4; i <= n; ++i) {
		g_FiboSimilar[i] = g_FiboSimilar[i - 1] + g_FiboSimilar[i - 3];
	}
	std::cout << g_FiboSimilar[n];
}