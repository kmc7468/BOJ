#include <cctype>
#include <iostream>
#include <string>

int main() {
	std::string program;
	std::cin >> program;

	int nop = 0;
	for (std::size_t i = 1; i < program.size(); ++i) {
		if (std::isupper(program[i])) {
			const std::size_t rem = (i + nop) % 4;
			if (rem) {
				nop += 4 - rem;
			}
		}
	}

	std::cout << nop;
}