#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

int main() {
	std::string digits;
	char digit;
	while (std::cin >> digit) {
		digits.push_back(digit);
	}

	std::sort(digits.begin(), digits.end(), std::greater<char>());
	std::cout << digits;
}