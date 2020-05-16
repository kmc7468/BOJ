#include <algorithm>
#include <iostream>

int main() {
	int costs[5];
	for (int i = 0; i < 5; ++i) {
		std::cin >> costs[i];
	}
	std::cout << *std::min_element(costs, costs + 3) + *std::min_element(costs + 3, costs + 5) - 50;
}