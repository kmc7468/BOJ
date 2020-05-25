#include <iostream>

long long g_Fibo[91]{ 0, 1 };

int main() {
	int n;
	std::cin >> n;

	for (int i = 2; i <= n; ++i) {
		g_Fibo[i] = g_Fibo[i - 1] + g_Fibo[i - 2];
	}
	std::cout << g_Fibo[n];
}