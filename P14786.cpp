#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

double f(double x, int a, int b, int c);
double df(double x, int a, int b);

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;

	std::srand(static_cast<unsigned>(std::time(nullptr)));
	double x = std::rand() / static_cast<double>(RAND_MAX);

	for (int i = 0; i < 100000; ++i) {
		const double oldX = x;
		x -= f(x, a, b, c) / df(x, a, b);
		if (std::fabs(oldX - x) < 10e-9) break;

	}
	std::cout << std::fixed << std::setprecision(9) << x << '\n';

}

double f(double x, int a, int b, int c) {
	return a * x + b * std::sin(x) - c;
}
double df(double x, int a, int b) {
	return a + b * std::cos(x);
}