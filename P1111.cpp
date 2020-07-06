#include <cmath>
#include <iostream>

int g_Sequence[50];

bool IsInteger(double x);

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> g_Sequence[i];
	}

	if (n == 1) {
	a:
		std::cout << 'A';
	} else if (n == 2) {
		if (g_Sequence[0] == g_Sequence[1]) {
			std::cout << g_Sequence[0];
		} else goto a;
	} else {
		double a = 1, b = 0;
		if (g_Sequence[0] == g_Sequence[1]) {
			if (g_Sequence[1] != g_Sequence[2]) {
			b:
				std::cout << 'B';
				return 0;
			}
		} else {
			a = (g_Sequence[2] - g_Sequence[1]) / (g_Sequence[1] - g_Sequence[0]);
			b = g_Sequence[2] - a * g_Sequence[1];

			if (!IsInteger(a) || !IsInteger(b)) goto b;
		}

		for (int i = 1; i < n; ++i) {
			if (a * g_Sequence[i - 1] + b != g_Sequence[i]) goto b;
		}
		std::cout << a * g_Sequence[n - 1] + b;
	}
}

bool IsInteger(double x) {
	double intPart;
	return std::modf(x, &intPart) == 0.0;
}