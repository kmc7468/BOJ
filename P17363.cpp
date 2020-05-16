#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::cin.get();

	std::vector<std::string> lines;
	for (int i = 0; i < n; ++i) {
		std::getline(std::cin, lines.emplace_back());
	}

	static const std::unordered_map<char, char> table = {
		{ '.', '.' },
		{ 'O', 'O' },
		{ '-', '|' },
		{ '|', '-' },
		{ '/', '\\' },
		{ '\\', '/' },
		{ '^', '<' },
		{ '<', 'v' },
		{ 'v', '>' },
		{ '>', '^' },
	};

	std::vector<std::string> rotated(m, std::string(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			rotated[m - j - 1][i] = table.at(lines[i][j]);
		}
	}

	for (const std::string& line : rotated) {
		std::cout << line << '\n';
	}
}