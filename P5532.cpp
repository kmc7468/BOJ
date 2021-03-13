#include <algorithm>
#include <iostream>

int main() {
	int l, a, b, c, d;
	std::cin >> l >> a >> b >> c >> d;

	const int k = a / c + !!(a % c);
	const int m = b / d + !!(b % d);
	std::cout << l - std::max(k, m);
}