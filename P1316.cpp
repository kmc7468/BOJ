#include <iostream>
#include <string>

int main() {
	int n;
	std::cin >> n;

	int count = 0;
	for (int i = 0; i < n; ++i) {
		std::string string;
		std::cin >> string;

		bool isGroupWord = true;
		int isExists['z' - 'a' + 1]{ 0 };
		char before = 0;
		for (const char c : string) {
			const int index = c - 'a';
			if (before && before != c) {
				isExists[before - 'a'] = 2;
			}

			switch (isExists[index]) {
			case 0: isExists[index] = 1; break;
			case 2: isGroupWord = false; break;
			}
			before = c;
		}

		count += isGroupWord;
	}

	std::cout << count;
}