#include <iostream>

int Zero(int n);
int One(int n);

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;
		std::cout << Zero(n) - 1 << ' ' << One(n) - 1 << '\n';
	}
}

int Zero(int n) {
	static int zeroNumber[42]{ 2, 1 };
	if (zeroNumber[n]) return zeroNumber[n];
	else return (zeroNumber[n] = Zero(n - 1) + Zero(n - 2) - 1);
}
int One(int n) {
	static int oneNumber[42]{ 1, 2 };
	if (oneNumber[n]) return oneNumber[n];
	else return (oneNumber[n] = One(n - 1) + One(n - 2) - 1);
}