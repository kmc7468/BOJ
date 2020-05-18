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

	for (int i = m; i < table.size(); ++i) {
		if (!table[i]) {
			std::cout << i << '\n';
		}
	}
}