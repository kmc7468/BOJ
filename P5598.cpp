#include <algorithm>
#include <iostream>
#include <string>

int main() {
	std::string string;
	std::cin >> string;

	std::transform(string.begin(), string.end(), string.begin(), [](char c) -> char {
		const int index = c - 'A' - 3;
		const int newIndex = (index + (index < 0 ? 26 : 0)) % ('Z' - 'A' + 1);
		return newIndex + 'A';
	});
	std::cout << string;
}