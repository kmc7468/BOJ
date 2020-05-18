#include <algorithm>
#include <iostream>
#include <vector>

int g_N;

std::istream& operator>>(std::istream& stream, std::vector<bool>& matrix);

int main() {
	std::cin >> g_N;

	std::vector<bool> a(g_N * g_N), b(g_N * g_N);
	std::cin >> a >> b;

	int count = 0;
	for (int i = 0; i < g_N; ++i) {
		for (int j = 0; j < g_N; ++j) {
			for (int k = 0; k < g_N; ++k) {
				if (a[i * g_N + k] && b[k * g_N + j]) {
					++count;
					break;
				}
			}
		}
	}

	std::cout << count;
}

std::istream& operator>>(std::istream& stream, std::vector<bool>& matrix) {
	for (int i = 0; i < g_N; ++i) {
		for (int j = 0; j < g_N; ++j) {
			int element;
			stream >> element;
			matrix[i * g_N + j] = !!element;
		}
	}
	return stream;
}