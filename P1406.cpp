#include <list>
#include <iostream>
#include <iterator>
#include <string>

int main() {
	std::string string;
	std::cin >> string;

	int n;
	std::cin >> n;
	std::cin.get();

	std::list<char> stringList(string.begin(), string.end());
	auto cursor = stringList.end();
	for (int i = 0; i < n; ++i) {
		char command;
		std::cin >> command;

		if (command == 'L') {
			if (cursor != stringList.begin()) {
				--cursor;
			}
		} else if (command == 'D') {
			if (cursor != stringList.end()) {
				++cursor;
			}
		} else if (command == 'B') {
			if (cursor != stringList.begin()) {
				stringList.erase(std::prev(cursor));
			}
		} else if (command == 'P') {
			std::cin.get();
			char character;
			std::cin >> character;
			std::cin.get();
			stringList.insert(cursor, character);
		}
	}

	for (const char c : stringList) {
		std::cout << c;
	}
}