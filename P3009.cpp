#include <iostream>

struct Point {
	int X, Y;
};

std::istream& operator>>(std::istream& stream, Point& point);

int main() {
	Point a, b, c;
	std::cin >> a >> b >> c;
	std::cout << (a.X == b.X ? c : (a.X == c.X ? b : a)).X << ' '
			  << (a.Y == b.Y ? c : (a.Y == c.Y ? b : a)).Y;
}

std::istream& operator>>(std::istream& stream, Point& point) {
	return stream >> point.X >> point.Y;
}