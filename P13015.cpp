#include <iostream>

void Star(int n, int i);
void Star(int n, int i, int j);

int main() {
	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		Star(n, i);
	}
	for (int i = n - 2; i >= 0; --i) {
		Star(n, i);
	}
}

void Star(int n, int i) {
	for (int j = 0; j < i; ++j) {
		std::cout << ' ';
	}
	for (int j = 0; j < n; ++j) {
		Star(n, i, j);
	}
	for (int j = 0; j < (n - i - 1) * 2 - 1; ++j) {
		std::cout << ' ';
	}
	for (int j = 0; j < n; ++j) {
		if (i == n - 1 && j == 0) continue;
		Star(n, i, j);
	}
	std::cout << '\n';
}
void Star(int n, int i, int j) {
	if (i == 0 || i == 2 * n - 2 || j == 0 || j == n - 1) {
		std::cout << '*';
	} else {
		std::cout << ' ';
	}
}