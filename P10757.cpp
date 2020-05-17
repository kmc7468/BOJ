#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

int GetDigit(const std::string& string, int digit);
void SetDigit(std::string& string, int digit, int number);

int main() {
	std::string a, b;
	std::cin >> a >> b;

	std::string result(std::max(a.size(), b.size()) + 1, '0');
	bool carry = false;
	for (std::size_t i = 0; i < result.size(); ++i) {
		const int number = GetDigit(a, i) + GetDigit(b, i) + carry;
		carry = number >= 10;
		SetDigit(result, i, number % 10);
	}

	const std::size_t start = result.find_first_not_of('0');
	std::cout << (start == std::string::npos ? "0" : result.substr(start));
}

int GetDigit(const std::string& string, int digit) {
	if (digit < string.size()) return string[string.size() - digit - 1] - '0';
	else return 0;
}
void SetDigit(std::string& string, int digit, int number) {
	string[string.size() - digit - 1] = number + '0';
}