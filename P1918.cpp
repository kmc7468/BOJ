#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

int main() {
	std::string expression;
	std::getline(std::cin, expression);

	const std::unordered_map<char, int> ranks = {
		{ '(', 3 }, { ')', 3 }, { '*', 1 }, { '/', 1 }, { '+', 2 }, { '-', 2 }
	};

	std::stack<char> stack;
	for (const char c : expression) {
		if (std::isalpha(c)) {
			std::cout << c;
		} else if (c == ')') {
			while (stack.top() != '(') {
				std::cout << stack.top();
				stack.pop();
			}
			stack.pop();
		} else {
			if (c != '(') {
				const int rank = ranks.at(c);
				while (!stack.empty() && ranks.at(stack.top()) <= rank) {
					std::cout << stack.top();
					stack.pop();
				}
			}
			stack.push(c);
		}
	}
	while (!stack.empty()) {
		std::cout << stack.top();
		stack.pop();
	}
}