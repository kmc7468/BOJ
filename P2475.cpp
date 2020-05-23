#include <iostream>

int main() {
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		int digit;
		std::cin >> digit;
		sum += digit * digit;
	}
	std::cout << sum % 10;
}