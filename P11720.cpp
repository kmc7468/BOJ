#include <iostream>

int main() {
	int n;
	std::cin >> n;
	std::cin.get();

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		char c;
		std::cin >> c;
		sum += c - '0';
	}

	std::cout << sum;
}