#include <ios>
#include <iostream>
#include <string>

bool IsNiceCommand(const std::string& command);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::string command;
		std::cin >> command;
		std::cout << IsNiceCommand(command) << '\n';
	}
}

bool IsNiceCommand(const std::string& command) {
	if (command.size() != 7) return false;

	const char alphabet[2] = { command[0], command[2] };
	if (alphabet[0] == alphabet[1]) return false;

	const int form[7] = { 0, 0, 1, 1, 0, 1, 1 };
	for (int i = 0; i < 7; ++i) {
		if (command[i] != alphabet[form[i]]) return false;
	}
	return true;
}