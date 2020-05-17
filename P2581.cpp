#include <cmath>
#include <iostream>
#include <vector>

int main() {
	int m, n;
	std::cin >> m >> n;

	const int root = static_cast<int>(std::sqrt(n));
	std::vector<bool> table(n + 1);
	table[1] = true;
	for (int i = 2; i <= root; ++i) {
		if (table[i]) continue;
		for (int j = i + i; j < table.size(); j += i) {
			table[j] = true;
		}
	}

	int min = n, sum = 0;
	for (int i = m; i < table.size(); ++i) {
		if (!table[i]) {
			sum += i;
			if (min > i) {
				min = i;
			}
		}
	}

	if (sum == 0) {
		std::cout << -1;
	} else {
		std::cout << sum << '\n' << min;
	}
}