#include <iostream>
#include <vector>

int main() {
	int n, x;
	std::cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		if (v < x) {
			std::cout << v << ' ';
		}
	}
}