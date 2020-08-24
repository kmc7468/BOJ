#include <cmath>
#include <ios>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while (true) {
		int n;
		std::cin >> n;
		if (!n) break;

		int c = 0;
		const int sqrt = static_cast<int>(std::sqrt(n));
		for (int i = 0; i <= sqrt; ++i) {
			const int i2 = i * i;
			if (i2 > n) break;

			for (int j = i; j <= sqrt; ++j) {
				const int j2 = i2 + j * j;
				if (j2 > n) break;

				for (int k = j; k <= sqrt; ++k) {
					const int k2 = j2 + k * k;
					if (k2 > n) break;

					for (int l = k; l <= sqrt; ++l) {
						const int l2 = k2 + l * l;
						if (l2 >= n) {
							c += l2 == n;
							break;
						}
					}
				}
			}
		}

		std::cout << c << '\n';
	}
}