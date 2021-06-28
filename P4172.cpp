#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <iterator>

#define M 1'000'000

int g_Sequence[M];

int GetTerm(int n);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::fill(std::begin(g_Sequence), std::end(g_Sequence), -1);
	g_Sequence[0] = 1;

	int i;
	while (std::cin >> i, i != -1) {
		std::cout << GetTerm(i) << '\n';
	}
}

int GetTerm(int n) {
	if (g_Sequence[n] != -1) return g_Sequence[n];
	else return g_Sequence[n] = (GetTerm(n - std::sqrt(n)) % M + GetTerm(std::log(n)) % M + GetTerm(n * std::pow(std::sin(n), 2)) % M) % M;
}