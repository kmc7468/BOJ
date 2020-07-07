#include <ios>
#include <iostream>

int g_Board[100][100];
char g_Ways[100][100][100];

bool IsNotZero(int i, int j);
void Add(int i1, int j1, int i2, int j2);
void Print(int i, int j);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> g_Board[i][j];
		}
	}

	g_Ways[0][0][99] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == n - 1 && j == n - 1) break;
			else if (!IsNotZero(i, j)) continue;

			const int moving = g_Board[i][j];
			if (i + moving < n) {
				Add(i + moving, j, i, j);
			}
			if (j + moving < n) {
				Add(i, j + moving, i, j);
			}
		}
	}

	Print(n - 1, n - 1);
}

bool IsNotZero(int i, int j) {
	for (int k = 0; k < 100; ++k) {
		if (g_Ways[i][j][k]) return true;
	}
	return false;
}
void Add(int i1, int j1, int i2, int j2) {
	bool carry = false;
	for (int k = 99; k >= 0; --k) {
		const int number = g_Ways[i1][j1][k] + g_Ways[i2][j2][k] + carry;
		carry = number >= 10;
		g_Ways[i1][j1][k] = number % 10;
	}
}
void Print(int i, int j) {
	bool begined = false;
	for (int k = 0; k < 100; ++k) {
		if (!begined && !g_Ways[i][j][k] && k != 99) continue;

		begined = true;
		std::cout << static_cast<char>(g_Ways[i][j][k] + '0');
	}
}