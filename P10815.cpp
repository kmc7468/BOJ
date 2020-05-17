#include <ios>
#include <iostream>
#include <unordered_map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::unordered_map<int, bool> table(n);
	for (int i = 0; i < n; ++i) {
		int number;
		std::cin >> number;
		table[number] = true;
	}

	int m;
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		int number;
		std::cin >> number;
		std::cout << (table.find(number) != table.end()) << ' ';
	}
}