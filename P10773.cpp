#include <deque>
#include <ios>
#include <iostream>
#include <numeric>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int k;
	std::cin >> k;

	std::deque<int> deque;
	for (int i = 0; i < k; ++i) {
		int number;
		std::cin >> number;
		if (number) {
			deque.push_back(number);
		} else {
			deque.pop_back();
		}
	}
	std::cout << std::accumulate(deque.begin(), deque.end(), 0);
}