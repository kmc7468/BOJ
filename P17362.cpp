#include <iostream>

int F(int n);

int main() {
	int n;
	std::cin >> n;
	std::cout << F(n);
}

int F(int n) {
	if (n <= 5) return n;
	else if (n <= 9) return 10 - n;
	else return F((n - 10) % 8 + 2);
}