#include <cmath>
#include <iostream>

int main() {
	int n, k;
	std::cin >> n >> k;

	int students[2][6]{ 0 };
	for (int i = 0; i < n; ++i) {
		int s, y;
		std::cin >> s >> y;
		++students[s][y - 1];
	}

	int sum = 0;
	for (const auto& years : students) {
		for (const auto& number : years) {
			const std::div_t div = std::div(number, k);
			sum += div.quot + !!div.rem;
		}
	}
	std::cout << sum;
}