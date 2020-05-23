#include <cstddef>
#include <iostream>
#include <stack>
#include <string>
#include <utility>

int main() {
	std::string string;
	std::cin >> string;

	std::stack<std::pair<std::size_t, int>> stack;
	stack.push(std::make_pair(0, 0));
	for (std::size_t i = 0; i < string.size(); ++i) {
		const char c = string[i];
		if (c == '(' || c == '[') {
			stack.push(std::make_pair(i, 0));
		} else {
			if (stack.size() == 1 || string[stack.top().first] != (c == ')' ? '(' : '[')) {
				std::cout << 0;
				return 0;
			}

			const auto [j, v] = stack.top();
			stack.pop();
			stack.top().second += (j + 1 == i ? 1 : v) * (c == ')' ? 2 : 3);
		}
	}

	std::cout << (stack.size() == 1 ? stack.top().second : 0);
}