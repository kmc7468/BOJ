#include <algorithm>
#include <iostream>
#include <string>

int main() {
	std::string a, b;
	std::cin >> a >> b;

	std::reverse(a.begin(), a.end());
	std::reverse(b.begin(), b.end());

	std::cout << std::max(std::stoi(a), std::stoi(b));
}