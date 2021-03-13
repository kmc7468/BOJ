#include <ios>
#include <iostream>
#include <string_view>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	bool isZero = true;
	while (true) {
		char digit;
		std::cin >> digit;
		if (std::cin.eof()) break;

		static constexpr std::string_view binary[] = {
			"000", "001", "010", "011", "100", "101", "110", "111",
			"", "1", "10", "11", "100", "101", "110", "111",
		};
		std::cout << binary[digit - '0' + (isZero ? 8 : 0)];
		isZero = isZero && digit == '0';
	}

	if (isZero) {
		std::cout << '0';
	}
}