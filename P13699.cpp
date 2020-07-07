#include <iostream>

unsigned long long g_T[36]{ 1 };

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			g_T[i] += g_T[j] * g_T[i - j - 1];
		}
	}
	std::cout << g_T[n];
}