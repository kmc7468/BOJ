#include <iostream>

int main() {
	int n;
	std::cin >> n;

	const int a = n / 2;
	const int b = n - a;
	std::cout << (a + 1) * (b + 1);
}