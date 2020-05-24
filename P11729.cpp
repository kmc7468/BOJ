#include <cmath>
#include <ios>
#include <iostream>

void Hanoi(int n, int from, int to);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::cout << static_cast<int>(std::pow(2, n) - 1) << '\n';
	Hanoi(n, 0, 2);
}

void Hanoi(int n, int from, int to) {
	if (n == 0) return;

	Hanoi(n - 1, from, 3 - from - to);
	std::cout << from + 1 << ' ' << to + 1 << '\n';
	Hanoi(n - 1, 3 - from - to, to);
}