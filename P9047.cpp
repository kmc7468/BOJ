#include <algorithm>
#include <iostream>
#include <string>

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::string n;
		std::cin >> n;

		int c = 0;
		while (n != "6174") {
			std::string max = n, min = n;
			std::sort(max.begin(), max.end(), std::greater<char>());
			std::sort(min.begin(), min.end());

			n = std::to_string(std::stoi(max) - std::stoi(min));
			n.insert(0, 4 - n.size(), '0');
			++c;
		}

		std::cout << c << '\n';
	}
}