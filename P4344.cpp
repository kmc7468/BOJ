#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int m;
		std::cin >> m;

		std::vector<int> scores;
		int sum = 0;
		for (int j = 0; j < m; ++j) {
			std::cin >> scores.emplace_back();
			sum += scores.back();
		}

		const double avg = sum / static_cast<double>(m);
		std::cout << std::fixed << std::setprecision(3) << std::count_if(scores.begin(), scores.end(), [avg](int score) {
			return score > avg;
		}) / static_cast<double>(m) * 100 << "%\n";
	}
}