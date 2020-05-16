#include <iostream>
#include <string>

int main() {
	std::string string;
	std::cin >> string;

	for (char c = 'a'; c <= 'z'; ++c) {
		std::cout << static_cast<int>(string.find(c)) << ' ';
	}
}