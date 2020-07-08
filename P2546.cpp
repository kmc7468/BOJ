#include <ios>
#include <iostream>

int g_CIQs[200000];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, m;
		std::cin >> n >> m;

		long long cIQSum = 0;
		for (int j = 0; j < n; ++j) {
			std::cin >> g_CIQs[j];
			cIQSum += g_CIQs[j];
		}

		long long eIQSum = 0;
		for (int j = 0; j < m; ++j) {
			int iq;
			std::cin >> iq;
			eIQSum += iq;
		}

		const double cIQA = cIQSum / static_cast<double>(n);
		const double eIQA = eIQSum / static_cast<double>(m);
		int count = 0;
		for (int j = 0; j < n; ++j) {
			const double newCIQA = (cIQSum - g_CIQs[j]) / static_cast<double>(n - 1);
			const double newEIQA = (eIQSum + g_CIQs[j]) / static_cast<double>(m + 1);
			if (newCIQA > cIQA && newEIQA > eIQA) {
				++count;
			}
		}

		std::cout << count << '\n';
	}
}