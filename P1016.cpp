#include <cmath>
#include <iostream>

using ll = long long;

bool g_IsSquared[1'000'000 + 1];

ll GetMutliple(ll x, ll y);

int main() {
	ll min, max;
	std::cin >> min >> max;

	ll n = max - min + 1;
	const ll root = std::sqrt(max);
	for (ll i = 2; i <= root; ++i) {
		if (i > 2 && (i & 1) == 0) continue;

		const ll squared = i * i;
		for (ll j = GetMutliple(min, squared); j <= max; j += squared) {
			if (!g_IsSquared[j - min]) {
				g_IsSquared[j - min] = true;
				--n;
			}
		}
	}

	std::cout << n;
}

ll GetMutliple(ll x, ll y) {
	const std::lldiv_t div = std::lldiv(x, y);
	if (div.rem == 0) return x;
	else return y - div.rem + x;
}