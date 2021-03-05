#include <algorithm>
#include <iostream>
#include <queue>

std::queue<int> g_Queue;
bool g_IsVisited[100'000 + 1];

void Visit(int n);

int main() {
	int n, k;
	std::cin >> n >> k;

	Visit(n);
	for (int s = 0; ; ++s) {
		int remained = g_Queue.size();
		while (remained) {
			const int current = g_Queue.front();
			g_Queue.pop();
			--remained;

			if (current == k) {
				std::cout << s << '\n';
				return 0;
			}

			Visit(current - 1);
			Visit(current * 2);
			Visit(current + 1);
		}
	}
}

void Visit(int n) {
	if (0 <= n && n <= 100'000 && !g_IsVisited[n]) {
		g_IsVisited[n] = true;
		g_Queue.push(n);
	}
}