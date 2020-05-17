#include <deque>
#include <iostream>
#include <numeric>

int main() {
	int n;
	std::cin >> n;

	std::deque<int> deque(n);
	std::iota(deque.begin(), deque.end(), 1);
	while (deque.size() > 1) {
		deque.pop_front();
		deque.push_back(deque.front());
		deque.pop_front();
	}

	std::cout << deque.front();
}