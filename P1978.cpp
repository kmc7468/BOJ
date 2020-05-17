#include <cmath>
#include <iostream>

bool IsPrime(int x);

int main() {
	int n;
	std::cin >> n;

	int count = 0;
	for (int i = 0; i < n; ++i) {
		int number;
		std::cin >> number;
		count += IsPrime(number);
	}

	std::cout << count;
}

bool IsPrime(int x) {
	const int root = static_cast<int>(std::sqrt(x));
	for (int i = 2; i <= root; ++i) {
		if (x % i == 0) return false;
	}
	return x >= 2;
}