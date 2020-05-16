#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

void Trim(std::string& string);
int CountWords(const std::string& string);

int main() {
	std::string word;
	std::getline(std::cin, word);
	Trim(word);

	std::cout << CountWords(word);
}

void Trim(std::string& string) {
	std::size_t removePrefix = 0, removeSuffix = 0;
	while (removePrefix < string.size() && string[removePrefix] == ' ') ++removePrefix;
	while (removeSuffix < string.size() - removePrefix && string[string.size() - removeSuffix - 1] == ' ') ++removeSuffix;

	string.erase(string.begin(), string.begin() + removePrefix);
	string.erase(string.end() - removeSuffix, string.end());
}
int CountWords(const std::string& string) {
	int count = !string.empty();
	std::size_t begin = 0, next;
	while ((next = string.find(' ', begin)) != std::string::npos) {
		++count;
		begin = next + 1;
	}
	return count;
}