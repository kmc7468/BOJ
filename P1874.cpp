#include <ios>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::stack<int> stack;
	std::string result;

	int lastPushed = 0;
	bool canMake = true;
	for (int i = 0; i < n; ++i) {
		int number;
		std::cin >> number;

		if (canMake) {
			if (number > lastPushed) {
				for (int j = lastPushed + 1; j <= number; ++j) {
					stack.push(j);
					result += "+\n";
				}
				lastPushed = number;
			}
			if (stack.empty() || stack.top() != number) {
				canMake = false;
			} else {
				stack.pop();
				result += "-\n";
			}
		}
	}

	std::cout << (canMake ? result : "NO");
}