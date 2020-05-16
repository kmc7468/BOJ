#include <algorithm>
#include <iostream>

int main() {
	int rems[42]{ 0 };
	for (int i = 0; i < 10; ++i) {
		int num;
		std::cin >> num;
		++rems[num % 42];
	}

	std::cout << std::count_if(rems, rems + 42, [](int rem) -> bool {
		return rem;
	});
}