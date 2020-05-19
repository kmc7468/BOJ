#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>

int main() {
	int n;
	std::cin >> n;
	std::cin.get();

	for (int i = 0; i < n; ++i) {
		std::string sentence;
		std::getline(std::cin, sentence);

		int alphabets['z' - 'a' + 2]{ 3, 0 };
		for (const char c : sentence) {
			if (std::isalpha(c)) {
				++alphabets[std::tolower(c) - 'a' + 1];
			}
		}

		const int pangram = *std::min_element(std::begin(alphabets), std::end(alphabets));
		static const char* pangrams[] = { "Not a pangram", "Pangram!", "Double pangram!!", "Triple pangram!!!" };
		std::cout << "Case " << i + 1 << ": " << pangrams[pangram] << '\n';
	}
}