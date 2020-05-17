#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> array(n);
	for (int& element : array) {
		std::cin >> element;
	}

	std::sort(array.begin(), array.end());
	int prev = 1'000'000 + 1;
	for (int element : array) {
		if (prev != element) {
			std::cout << element << '\n';
			prev = element;
		}
	}
}