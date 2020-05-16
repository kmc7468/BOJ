#include <cmath>
#include <iostream>

bool g_IsSelfNumber[10'000 + 1];

int D(int n);

int main() {
	for (int i = 1; i <= 10'000; ++i) {
		g_IsSelfNumber[D(i)] = true;
	}

	for (int i = 1; i <= 10'000; ++i) {
		if (!g_IsSelfNumber[i]) {
			std::cout << i << '\n';
		}
	}
}

int D(int n) {
	int result = n;
	while (n) {
		const std::div_t div = std::div(n, 10);
		result += div.rem;
		n = div.quot;
	}
	return result;
}