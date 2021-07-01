#include <iostream>
#include <string>

int main() {
	int n;
	std::cin >> n;

	std::string string;
	std::cin >> string;

	for (int i = 0; i < n / 2; ++i) {
		const int j = n - i - 1;
		if (string[i] == '?' && string[j] == '?') {
			string[i] = string[j] = 'a';
		} else if (string[i] == '?') {
			string[i] = string[j];
		} else {
			string[j] = string[i];
		}
	}

	if (n % 2 == 1 && string[(n - 1) / 2] == '?') {
		string[(n - 1) / 2] = 'a';
	}

	std::cout << string;
}