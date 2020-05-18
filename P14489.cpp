#include <iostream>

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;
	std::cout << a + b - (a + b >= c * 2 ? c * 2 : 0);
}