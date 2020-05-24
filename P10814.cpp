#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<std::pair<int, std::string>> people(n);
	for (auto& [age, name] : people) {
		std::cin >> age >> name;
	}

	std::stable_sort(people.begin(), people.end(), [](const auto& a, const auto& b) {
		return a.first < b.first;
	});
	for (const auto& [age, name] : people) {
		std::cout << age << ' ' << name << '\n';
	}
}