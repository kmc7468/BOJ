#include <algorithm>
#include <iostream>

static constexpr long long g_Cycle = 15 * 100000;
int g_Fibo[g_Cycle]{ 0, 1 };

int main() {
	long long n;
	std::cin >> n;

	const int loop = static_cast<int>(std::min(g_Cycle - 1, n));
	for (int i = 2; i <= loop; ++i) {
		g_Fibo[i] = (g_Fibo[i - 1] + g_Fibo[i - 2]) % 1000000;
	}

	std::cout << g_Fibo[n % g_Cycle];
}