#include <cmath>
#include <iostream>

int main() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	c += d;
	std::div_t div = std::div(c, 60);
	b += div.quot;
	c = div.rem;
	div = std::div(b, 60);
	a += div.quot;
	b = div.rem;
	a %= 24;

	std::cout << a << ' ' << b << ' ' << c;
}