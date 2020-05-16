#include <cctype>
#include <iostream>
#include <string>

int main() {
	std::string string;
	std::cin >> string;

	int count['Z' - 'A' + 1]{ 0 };
	for (const char c : string) {
		++count[std::toupper(c) - 'A'];
	}

	char maxAlphabet = 0;
	int maxCount = 0;
	for (char c = 'A'; c <= 'Z'; ++c) {
		if (count[c - 'A'] >= maxCount) {
			if (maxCount == count[c - 'A']) {
				maxAlphabet = '?';
			} else {
				maxAlphabet = c;
				maxCount = count[c - 'A'];
			}
		}
	}

	std::cout << maxAlphabet;
}