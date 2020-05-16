#include <iostream>

int main() {
	int year;
	std::cin >> year;
	std::cout << (year % 100 == 0 ? (year % 400 == 0 ? 1 : 0) : (year % 4 ? 0 : 1));
}