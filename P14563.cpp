#include <cmath>
#include <ios>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;

		const int root = static_cast<int>(std::sqrt(n));
		int sum = n != 1;
		for (int i = 2; i <= root; ++i) {
			if (n % i == 0) {
				const int other = n / i;
				sum += i + (i != other ? other : 0);
			}
		}

		std::cout << (n == sum ? "Perfect\n" : (n < sum ? "Abundant\n" : "Deficient\n"));
	}
}