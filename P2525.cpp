#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	a += c / 60;

	const int newB = (b + c) % 60;
	const int newA = (a + (newB < b)) % 24;
	std::cout << newA << ' ' << newB;
}