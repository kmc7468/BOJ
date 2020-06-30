#include <ios>
#include <iostream>

int g_MatrixA[100][100];
int g_MatrixB[100][100];
int g_MatrixC[100][100];

void ReadMatrix(int(&matrix)[100][100], int h, int w);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, k;
	std::cin >> n >> m;
	ReadMatrix(g_MatrixA, n, m);
	std::cin >> m >> k;
	ReadMatrix(g_MatrixB, m, k);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			for (int l = 0; l < m; ++l) {
				g_MatrixC[i][j] += g_MatrixA[i][l] * g_MatrixB[l][j];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			std::cout << g_MatrixC[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void ReadMatrix(int(&matrix)[100][100], int h, int w) {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			std::cin >> matrix[i][j];
		}
	}
}