#include <iostream>

int main() {
	int sum = 0;
	for (int i = 0; i < 5; ++i) {
		int s;
		std::cin >> s;
		sum += s;
	}
	std::cout << sum;
}