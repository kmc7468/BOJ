#include <iomanip>
#include <ios>
#include <iostream>

int g_Colors[100];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	double p;
	int n;
	std::cin >> p >> n;

	for (int i = 0; i < n; ++i) {
		int s, l = 100;
		char d;
		std::cin >> s >> d;

		if (d == 'L') {
			l = s - 1;
			s = 0;
		}

		for (int j = s; j < l; ++j) {
			++g_Colors[j] %= 3;
		}
	}

	int count[3]{ 0 };
	for (int i = 0; i < 100; ++i) {
		++count[g_Colors[i]];
	}

	std::cout << std::fixed << std::setprecision(2);
	for (int i = 0; i < 3; ++i) {
		std::cout << p * count[i] / 100 << '\n';
	}
}