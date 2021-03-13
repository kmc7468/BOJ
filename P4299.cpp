#include <iostream>

int main() {
	int sum, diff;
	std::cin >> sum >> diff;

	if ((sum + diff) & 1 || sum < diff) {
		std::cout << -1;
	} else {
		std::cout << (sum + diff) / 2 << ' ' << (sum - diff) / 2;
	}
}