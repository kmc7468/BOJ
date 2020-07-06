#include <iostream>

int main() {
	double n1, n2, n12;
	std::cin >> n1 >> n2 >> n12;
	std::cout << static_cast<int>((n1 + 1) * (n2 + 1) / (n12 + 1) - 1);
}