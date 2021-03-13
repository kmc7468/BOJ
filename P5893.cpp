#include <algorithm>
#include <cstring>
#include <ios>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	char binary[1006] = { '0' };
	std::cin >> binary + 1;

	const int length = std::strlen(binary) - 1;
	std::fill_n(binary + length + 1, 4, '0');

	bool carry = false;
	for (int i = length + 4; i >= 0; --i) {
		if ((binary[i] += (length + 4 - i < length ? binary[i - 4] - '0' : 0) + carry) >= '2') {
			binary[i] -= 2;
			carry = true;
		} else {
			carry = false;
		}
	}

	bool isZero = true;
	for (int i = 0; i < length + 5; ++i) {
		if (!isZero || binary[i] != '0') {
			std::cout << binary[i];
			isZero = false;
		}
	}
}