#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::queue<int> queue;
	for (int i = 0; i < n; ++i) {
		std::string command;
		std::cin >> command;

		static const std::unordered_map<std::string, int> table = {
			{ "push", 0 },
			{ "pop", 1 },
			{ "size", 2 },
			{ "empty", 3 },
			{ "front", 4 },
			{ "back", 5 },
		};
		switch (table.at(command)) {
		case 0: {
			int value;
			std::cin >> value;
			queue.push(value);
			break;
		}

		case 1:
			if (queue.empty()) {
				std::cout << "-1\n";
			} else {
				std::cout << queue.front() << '\n';
				queue.pop();
			}
			break;

		case 2:
			std::cout << queue.size() << '\n';
			break;

		case 3:
			std::cout << queue.empty() << '\n';
			break;

		case 4:
			if (queue.empty()) {
				std::cout << "-1\n";
			} else {
				std::cout << queue.front() << '\n';
			}
			break;

		case 5:
			if (queue.empty()) {
				std::cout << "-1\n";
			} else {
				std::cout << queue.back() << '\n';
			}
			break;
		}
	}
}