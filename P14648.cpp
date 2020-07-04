#include <ios>
#include <iostream>
#include <utility>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, q;
	std::cin >> n >> q;

	std::vector<int> sequence(n);
	for (int& num : sequence) {
		std::cin >> num;
	}

	for (int i = 0; i < q; ++i) {
		int query, a, b, c, d;
		std::cin >> query >> a >> b;

		long long abSum = 0;
		for (int j = a - 1; j < b; ++j) {
			abSum += sequence[j];
		}

		if (query == 1) {
			std::cout << abSum << '\n';
			std::swap(sequence[a - 1], sequence[b - 1]);
		} else {
			std::cin >> c >> d;

			long long cdSum = 0;
			for (int j = c - 1; j < d; ++j) {
				cdSum += sequence[j];
			}

			std::cout << abSum - cdSum << '\n';
		}
	}
}