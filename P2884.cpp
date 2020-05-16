#include <iostream>

int main() {
	int h, m;
	std::cin >> h >> m;

	const int newM = (m - 45) % 60 + (m < 45 ? 60 : 0);
	h -= (m < 45) + (h == 0 && m < 45 ? -24 : 0);

	std::cout << h << ' ' << newM;
}