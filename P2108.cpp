#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <iterator>
#include <vector>

int g_Frequencies[8'001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> array(n);
	int sum = 0;
	for (int& element : array) {
		std::cin >> element;
		sum += element;
		++g_Frequencies[element + 4000];
	}

	std::sort(array.begin(), array.end());
	std::cout << static_cast<int>(std::round(sum / static_cast<double>(n))) << '\n'
			  << array[n / 2] << '\n';

	int* const firstMode = std::max_element(std::begin(g_Frequencies), std::end(g_Frequencies));
	int* const secondMode = std::max_element(firstMode + 1, std::end(g_Frequencies));
	std::cout << std::distance(std::begin(g_Frequencies), *firstMode == *secondMode ? secondMode : firstMode) - 4000 << '\n'
			  << array.back() - array.front();
}