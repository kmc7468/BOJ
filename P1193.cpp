#include <cmath>
#include <iostream>

int main() {
	int n;
	std::cin >> n;

	const int sum = static_cast<int>(std::ceil(std::sqrt(2 * n + 0.25) - 0.5));
	const int rawIndex = sum * (sum + 1) / 2 - n;
	const int index = sum & 1 ? sum - rawIndex - 1 : rawIndex;
	std::cout << sum - index << '/' << index + 1;
}