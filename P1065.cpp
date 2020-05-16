#include <cmath>
#include <iostream>
#include <string>

bool IsHansu(int n);

int main() {
	int n;
	std::cin >> n;

	int count = 0;
	for (int i = 1; i <= n; ++i) {
		count += IsHansu(i);
	}
	std::cout << count;
}

bool IsHansu(int n) {
	if (n < 100) return true;

	const std::string nStr = std::to_string(n);
	for (auto iter = nStr.rbegin() + 1; iter < nStr.rend() - 1; ++iter) {
		if ((*iter - '0') - (*(iter - 1) - '0') != (*(iter + 1) - '0') - (*iter - '0')) return false;
	}

	return true;
}