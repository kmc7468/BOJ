#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

int Dot(const std::vector<int>& a, const std::vector<int>& b);

int main() {
	int n;
	std::cin >> n;

	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}

	std::sort(a.begin(), a.end(), [](int a, int b) {
		return a > b;
	});
	std::sort(b.begin(), b.end());
	std::cout << Dot(a, b);
}

int Dot(const std::vector<int>& a, const std::vector<int>& b) {
	int result = 0;
	for (std::size_t i = 0; i < a.size(); ++i) {
		result += a[i] * b[i];
	}
	return result;
}