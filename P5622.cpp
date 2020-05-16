#include <iostream>
#include <string>

int GetSeconds(char c);

int main() {
	std::string string;
	std::cin >> string;

	int sum = 0;
	for (const char c : string) {
		sum += GetSeconds(c);
	}
	std::cout << sum;
}

int GetSeconds(char c) {
	if (c <= 'O') return (c - 'A') / 3 + 3;
	else if (c <= 'S') return 8;
	else if (c <= 'V') return 9;
	else return 10;
}