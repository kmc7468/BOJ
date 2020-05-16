#include <cstddef>
#include <iostream>
#include <string>

char Char(const std::string& string, std::size_t i);

int main() {
	std::string string;
	std::cin >> string;

	int count = 0;
	for (std::size_t i = 0; i < string.size(); ++i) {
		if (string[i] == '=' || string[i] == '-') {
			if (string[i] == '=' && Char(string, i - 1) == 'z' && Char(string, i - 2) == 'd') {
				--count;
			}
		} else if (string[i] != 'j' || Char(string, i - 1) != 'l' && Char(string, i - 1) != 'n') {
			++count;
		}
	}

	std::cout << count;
}

char Char(const std::string& string, std::size_t i) {
	if (i < string.size()) return string[i];
	else return 0;
}