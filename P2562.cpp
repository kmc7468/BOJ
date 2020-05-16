#include <iostream>

int main() {
	int max = 0, maxLine;
	for (int i = 0; i < 9; ++i) {
		int v;
		std::cin >> v;
		if (v > max) {
			max = v;
			maxLine = i + 1;
		}
	}
	std::cout << max << '\n' << maxLine;
}