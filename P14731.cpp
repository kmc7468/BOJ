#include <ios>
#include <iostream>

static constexpr int g_Divider = 1000000007;

int Power(int e);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		int c, k;
		std::cin >> c >> k;

		const long long x = Power(k - 1);
		sum += (x * c % g_Divider * k) % g_Divider;
	}

	std::cout << sum % g_Divider;
}

int Power(int e) {
	if (e < 2) return e + 1;

	const long long temp = Power(e / 2);
	return temp * temp * ((e & 1) + 1) % g_Divider;
}