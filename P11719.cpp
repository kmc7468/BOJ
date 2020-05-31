#include <ios>
#include <iostream>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string string;
	while (std::getline(std::cin, string)) {
		std::cout << string << '\n';
	}
}