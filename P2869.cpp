#include <algorithm>
#include <cmath>
#include <iostream>

int main() {
	int a, b, v;
	std::cin >> a >> b >> v;

	std::cout << static_cast<int>(std::ceil(static_cast<double>(v - b) / (a - b)));
}