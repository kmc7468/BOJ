#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Point {
	int X, Y;
};

std::ostream& operator<<(std::ostream& stream, const Point& point);
std::istream& operator>>(std::istream& stream, Point& point);

int main() {
	int n;
	std::cin >> n;

	std::vector<Point> points(n);
	for (Point& point : points) {
		std::cin >> point;
	}

	std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
		if (a.X != b.X) return a.X < b.X;
		else return a.Y < b.Y;
	});
	for (const Point& point : points) {
		std::cout << point;
	}
}

std::ostream& operator<<(std::ostream& stream, const Point& point) {
	return stream << point.X << ' ' << point.Y << '\n';
}
std::istream& operator>>(std::istream& stream, Point& point) {
	return stream >> point.X >> point.Y;
}