#include <iostream>

int main() {
	int n;
	std::cin >> n;
	std::cout << static_cast<int>(n * 0.78) << ' ' << static_cast<int>(n * 0.956);
}