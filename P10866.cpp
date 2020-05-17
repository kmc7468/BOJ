#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::deque<int> deque;
	for (int i = 0; i < n; ++i) {
		std::string command;
		std::cin >> command;

		static const std::unordered_map<std::string, int> table = {
			{ "push_front", 0 },
			{ "push_back", 1 },
			{ "pop_front", 2 },
			{ "pop_back", 3 },
			{ "size", 4 },
			{ "empty", 5 },
			{ "front", 6 },
			{ "back", 7 },
		};
		switch (table.at(command)) {
		case 0: {
			int value;
			std::cin >> value;
			deque.push_front(value);
			break;
		}

		case 1: {
			int value;
			std::cin >> value;
			deque.push_back(value);
			break;
		}

		case 2:
			if (deque.empty()) {
				std::cout << "-1\n";
			} else {
				std::cout << deque.front() << '\n';
				deque.pop_front();
			}
			break;

		case 3:
			if (deque.empty()) {
				std::cout << "-1\n";
			} else {
				std::cout << deque.back() << '\n';
				deque.pop_back();
			}
			break;

		case 4:
			std::cout << deque.size() << '\n';
			break;

		case 5:
			std::cout << deque.empty() << '\n';
			break;

		case 6:
			if (deque.empty()) {
				std::cout << "-1\n";
			} else {
				std::cout << deque.front() << '\n';
			}
			break;

		case 7:
			if (deque.empty()) {
				std::cout << "-1\n";
			} else {
				std::cout << deque.back() << '\n';
			}
			break;
		}
	}
}