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
	for (int element : array) {
		std::cout << element << '\n';
	}
}