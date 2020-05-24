#include <iostream>

int Fac(int n);

int main() {
	int n;
	std::cin >> n;
	std::cout << Fac(n);
}

int Fac(int n) {
	if (n == 0) return 1;
	else return n * Fac(n - 1);
}