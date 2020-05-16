#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

int main() {
	int dec;
	std::cin >> dec;

	std::string result;
	while (dec) {
		std::div_t div = std::div(dec, 9);
		result.push_back(div.rem + '0');
		dec = div.quot;
	}

	std::reverse(result.begin(), result.end());
	std::cout << result;
}