#include <iomanip>
#include <iostream>

int main() {
	double a, b;
	std::cin >> a >> b;
	std::cout << std::setprecision(15) << (a / b);
}