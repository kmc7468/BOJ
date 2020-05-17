#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<int> array(n);
	for (int& element : array) {
		std::cin >> element;
	}

	std::sort(array.begin(), array.end());
	int prev = 1'000 + 1;
	for (int element : array) {
		if (prev != element) {
			std::cout << element << ' ';
			prev = element;
		}
	}
}