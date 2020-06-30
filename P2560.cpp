#include <iostream>

int g_Populations[1'000'000 + 1];

int Rem(int a, int b);

int main() {
	int a, b, d, n;
	std::cin >> a >> b >> d >> n;

	for (int i = 0; i <= n; ++i) {
		if (i < a) {
			g_Populations[i] = 1;
		} else if (a <= i && i < b) {
			g_Populations[i] = Rem(g_Populations[i - 1] + g_Populations[i - a], 1000);
		} else if (i != d) {
			g_Populations[i] = Rem(g_Populations[i - 1] + g_Populations[i - a] - g_Populations[i - b], 1000);
		} else {
			g_Populations[i] = Rem(g_Populations[i - 1] + g_Populations[i - a] - g_Populations[i - b] - 1, 1000);
		}
	}

	std::cout << g_Populations[n];
}

int Rem(int a, int b) {
	return (a % b + b) % b;
}