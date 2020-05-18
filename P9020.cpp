#include <iostream>

int main() {
	bool isNotPrime[10'000 + 1]{ false };
	for (int i = 2; i <= 100; ++i) {
		if (isNotPrime[i]) continue;
		for (int j = i + i; j <= 10'000; j += i) {
			isNotPrime[j] = true;
		}
	}

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;

		int a = 0, b = 0;
		for (int j = 2; j <= n / 2; ++j) {
			if (isNotPrime[j] || isNotPrime[n - j]) continue;
			a = j;
			b = n - j;
		}
		std::cout << a << ' ' << b << '\n';
	}
}