#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

int main() {
	while (true) {
		int n;
		std::cin >> n;
		if (!n) break;

		const int root = static_cast<int>(std::sqrt(2 * n));
		std::vector<bool> table(2 * n + 1);
		table[0] = table[1] = true;
		for (int i = 2; i <= root; ++i) {
			if (table[i]) continue;
			for (int j = i + i; j < table.size(); j += i) {
				table[j] = true;
			}
		}

		std::cout << std::count_if(table.begin() + n + 1, table.end(), std::logical_not<bool>()) << '\n';
	}
}