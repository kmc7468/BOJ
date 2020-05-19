#include <cmath>
#include <iostream>
#include <string>

int main() {
	int a, b;
	std::cin >> a >> b;

	std::div_t div = std::div(a, b);
	std::cout << div.quot;

	std::string decimal;
	while (div.rem && decimal.size() < 1000) {
		div = std::div(div.rem * 10, b);
		decimal.push_back(div.quot + '0');
	}
	if (!decimal.empty()) {
		std::cout << '.' << decimal;
	}
}