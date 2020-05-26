#include <ios>
#include <iostream>
#include <stack>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string string;
	while (std::getline(std::cin, string, '.')) {
		if (string.empty() || string.size() == 1 && string.front() == '\n') break;

		std::stack<char> stack;
		bool hasError = false;
		for (const char c : string) {
			if (c == '(' || c == '[') {
				stack.push(c);
			} else if (c == ')' || c == ']') {
				if (stack.empty() || stack.top() != (c == ')' ? '(' : '[')) {
					hasError = true;
					break;
				}
				stack.pop();
			}
		}

		std::cout << (stack.empty() && !hasError ? "yes\n" : "no\n");
	}
}