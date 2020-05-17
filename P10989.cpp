#include <ios>
#include <iostream>

int array[10'000];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		int number;
		std::cin >> number;
		++array[number - 1];
	}

	for (int i = 0; i < 10000; ++i) {
		for (int j = 0; j < array[i]; ++j) {
			std::cout << i + 1 << '\n';
		}
	}
}