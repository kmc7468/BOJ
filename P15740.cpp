#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

int GetDigit(const std::string& string, int digit, bool isNegative = false);
void SetDigit(std::string& string, int digit, int number);
bool IsBigger(const std::string& a, const std::string& b);

void Add(std::string& result, const std::string& a, const std::string& b);
void Sub(std::string& result, const std::string& a, const std::string& b);

int main() {
	std::string a, b;
	std::cin >> a >> b;

	const bool isANegative = a.front() == '-';
	const bool isBNegative = b.front() == '-';
	if (isANegative) {
		a.erase(a.begin());
	}
	if (isBNegative) {
		b.erase(b.begin());
	}
	const bool isAAbsBigger = IsBigger(a, b);

	std::string result(std::max(a.size(), b.size()) + 1, '0');
	if (isANegative == isBNegative) {
		Add(result, a, b);
		if (isANegative) {
			std::cout << '-';
		}
	} else {
		Sub(result, isAAbsBigger ? a : b, isAAbsBigger ? b : a);
		if (a != b && (isANegative && isAAbsBigger || isBNegative && !isAAbsBigger)) {
			std::cout << '-';
		}
	}

	const std::size_t start = result.find_first_not_of('0');
	std::cout << (start == std::string::npos ? "0" : result.substr(start));
}

int GetDigit(const std::string& string, int digit, bool isNegative) {
	const int number = digit < string.size() ? string[string.size() - digit - 1] - '0' : 0;
	return isNegative ? -number : number;
}
void SetDigit(std::string& string, int digit, int number) {
	string[string.size() - digit - 1] = number + '0';
}
bool IsBigger(const std::string& a, const std::string& b) {
	if (a.size() != b.size()) return a.size() >= b.size();
	for (std::size_t i = 0; i < a.size(); ++i) {
		if (a[i] > b[i]) return true;
		else if (a[i] < b[i]) return false;
	}
	return true;
}

void Add(std::string& result, const std::string& a, const std::string& b) {
	bool carry = false;
	for (std::size_t i = 0; i < result.size(); ++i) {
		const int number = GetDigit(a, i) + GetDigit(b, i) + carry;
		carry = number >= 10;
		SetDigit(result, i, number % 10);
	}
}
void Sub(std::string& result, const std::string& a, const std::string& b) {
	bool carry = false;
	for (std::size_t i = 0; i < result.size(); ++i) {
		int number = GetDigit(a, i) - GetDigit(b, i) - carry;
		if ((carry = number < 0)) {
			number += 10;
		}
		SetDigit(result, i, number % 10);
	}
}