#include <iostream>

int Fibo(int n);

int main() {
	int n;
	std::cin >> n;
	std::cout << Fibo(n);
}

int Fibo(int n) {
	if (n < 2) return n;
	else return Fibo(n - 1) + Fibo(n - 2);
}