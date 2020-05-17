#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::stack<int> stack;
	for (int i = 0; i < n; ++i) {
		std::string command;
		std::cin >> command;

		static const std::unordered_map<std::string, int> table = {
			{ "push", 0 },
			{ "pop", 1 },
			{ "size", 2 },
			{ "empty", 3 },
			{ "top", 4 },
		};
		switch (table.at(command)) {
		case 0: {
			int value;
			std::cin >> value;
			stack.push(value);
			break;
		}

		case 1:
			if (stack.empty()) {
				std::cout << "-1\n";
			} else {
				std::cout << stack.top() << '\n';
				stack.pop();
			}
			break;

		case 2:
			std::cout << stack.size() << '\n';
			break;

		case 3:
			std::cout << stack.empty() << '\n';
			break;

		case 4:
			if (stack.empty()) {
				std::cout << "-1\n";
			} else {
				std::cout << stack.top() << '\n';
			}
			break;
		}
	}
}