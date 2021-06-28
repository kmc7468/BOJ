#include <cstddef>
#include <ios>
#include <iostream>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::string firstFilename;
	std::cin >> firstFilename;

	for (int i = 1; i < n; ++i) {
		std::string filename;
		std::cin >> filename;
		for (std::size_t i = 0; i < firstFilename.size(); ++i) {
			if (firstFilename[i] != filename[i]) {
				firstFilename[i] = '?';
			}
		}
	}

	std::cout << firstFilename;
}