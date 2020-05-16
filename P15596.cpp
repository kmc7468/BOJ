#include <numeric>
#include <vector>

long long sum(std::vector<int>& a) {
	return std::accumulate(a.begin(), a.end(), 0ll);
}