#include <algorithm>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>

int g_Bingo[500][500];
int g_RowCount9[500], g_ColCount9[500];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	int count9 = 0, max = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::string num;
			std::cin >> num;

			g_Bingo[i][j] = std::count(num.begin(), num.end(), '9');
			if (g_Bingo[i][j]) {
				count9 += g_Bingo[i][j];
				g_RowCount9[i] += g_Bingo[i][j];
				g_ColCount9[j] += g_Bingo[i][j];
			}
		}
	}

	const int rowCount9Max = *std::max_element(std::begin(g_RowCount9), std::end(g_RowCount9));
	const int colCount9Max = *std::max_element(std::begin(g_ColCount9), std::end(g_ColCount9));
	std::cout << count9 - std::max(rowCount9Max, colCount9Max);
}