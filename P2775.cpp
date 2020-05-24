#include <iostream>
#include <numeric>
#include <vector>

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int k, n;
		std::cin >> k >> n;

		std::vector<int> rooms(n);
		std::iota(rooms.begin(), rooms.end(), 1);

		int sum = n * (n + 1) / 2;
		for (int j = 0; j < k; ++j) {
			int newSum = 0;
			for (int l = n - 1; l >= 0; --l) {
				const int old = rooms[l];
				newSum += (rooms[l] = sum);
				sum -= old;
			}
			sum = newSum;
		}
		std::cout << rooms.back() << '\n';
	}
}