#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;

	const int cn = n + (m -= n) - 1;
	if (m > n - 1) {
		m = n - 1;
	}

	unsigned long long result = 1;
	for (int i = 0; i < m; ++i) {
		result *= cn - i;
	}
	for (int i = 2; i <= m; ++i) {
		result /= i;
	}
	std::cout << result;
}