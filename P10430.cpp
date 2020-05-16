#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << (a + b) % c << '\n'
			  << (a % c + b % c) % c << '\n'
			  << (a * b) % c << '\n'
			  << ((a % c) * (b % c)) % c << '\n';
}