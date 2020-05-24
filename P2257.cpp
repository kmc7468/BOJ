#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>

int Calc(const std::string& expr, std::size_t& index);

int main() {
	std::string expr;
	std::cin >> expr;

	std::size_t i = 0;
	std::cout << Calc(expr, i);
}

int Calc(const std::string& expr, std::size_t& index) {
	static const std::unordered_map<char, int> mass = {
		{ 'H', 1 }, { 'C', 12 }, { 'O', 16 }
	};

	int sum = 0, last = 0;
	for (; index < expr.size(); ++index) {
		const char c = expr[index];
		if (std::isalpha(c)) {
			sum += last;
			last = mass.at(c);
		} else if (std::isdigit(c)) {
			sum += last * (c - '0');
			last = 0;
		} else if (c == '(') {
			sum += last;
			last = Calc(expr, index += 1);
		} else if (c == ')') break;
	}

	return sum + last;
}