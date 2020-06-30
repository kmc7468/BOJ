#include <iostream>
#include <string>

int main() {
	std::string k;
	std::cin >> k;

	if (k.size() == 1) {
		std::cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	} else {
		const int delta = k[0] - k[1];
		for (std::size_t i = 1; i < k.size() - 1; ++i) {
			if (k[i] - k[i + 1] != delta) {
				std::cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
				return 0;
			}
		}
		std::cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
	}
}