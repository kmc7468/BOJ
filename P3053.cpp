#include <iomanip>
#include <iostream>

int main() {
	int r;
	std::cin >> r;
	std::cout << std::fixed << std::setprecision(5) << r * r * 3.141592653589793 << '\n' << r * r * 2;
}