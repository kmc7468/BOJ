#include <cctype>
#include <iostream>
#include <string>
#include <unordered_set>

int main() {
	std::string word;
	bool isFirst = true;
	while (std::cin >> word) {
		if (!isFirst) {
			static const std::unordered_set<std::string> ignores = {
				"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"
			};
			if (ignores.find(word) != ignores.end()) continue;
		}
		isFirst = false;

		std::cout << static_cast<char>(std::toupper(word.front()));
	}
}