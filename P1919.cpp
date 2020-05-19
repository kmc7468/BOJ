#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

int main() {
	std::string a, b;
	std::cin >> a >> b;

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	std::string diff;
	std::set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(diff));
	std::cout << diff.size();
}