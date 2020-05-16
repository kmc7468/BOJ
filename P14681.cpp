#include <iostream>

int main() {
	int x, y;
	std::cin >> x >> y;

	static constexpr int area[2][2] = { 1, 4, 2, 3 };
	std::cout << area[x < 0][y < 0];
}