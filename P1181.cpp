#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<std::string> words(n);
	for (std::string& word : words) {
		std::cin >> word;
	}

	std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
		if (a.size() != b.size()) return a.size() < b.size();
		else return a < b;
	});

	const std::string* before = nullptr;
	for (const std::string& word : words) {
		if (!before || *before != word) {
			std::cout << word << '\n';
			before = &word;
		}
	}
}