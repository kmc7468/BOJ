#include <iostream>
#include <string>

int main() {
	std::string string;
	while (std::getline(std::cin, string)) {
		std::cout << string << '\n';
	}
}