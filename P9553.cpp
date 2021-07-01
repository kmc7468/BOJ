#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <map>
#include <numbers>
#include <utility>

#define PI std::numbers::pi_v<double>

class Interval {
private:
	std::map<double, int> m_Intervals{ { 0, 0 } };

public:
	void AddInterval(double begin, double end);
	std::map<double, int>::iterator FindInterval(double value);
	double GetMean() const;
};

double GetAngle(int x, int y);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout << std::fixed << std::setprecision(5);

	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;

		Interval interval;
		for (int j = 0; j < n; ++j) {
			int x1, y1, x2, y2;
			std::cin >> x1 >> y1 >> x2 >> y2;

			double angle1 = GetAngle(x1, y1);
			double angle2 = GetAngle(x2, y2);
			if (angle1 > angle2) {
				std::swap(angle1, angle2);
			}

			if (angle2 - angle1 < PI) {
				interval.AddInterval(angle1, angle2);
			} else {
				interval.AddInterval(0, angle1);
				interval.AddInterval(angle2, 2 * PI);
			}
		}

		std::cout << interval.GetMean() << '\n';
	}
}

void Interval::AddInterval(double begin, double end) {
	const auto beginIter = FindInterval(begin);
	const auto endIter = FindInterval(end);
	const auto endValue = *endIter;

	if (beginIter != endIter) {
		const auto realEndIter = std::next(endIter);
		for (auto iter = std::next(beginIter); iter != realEndIter; ++iter) {
			++(iter->second);
		}
	}

	m_Intervals[begin] = beginIter->second + 1;
	m_Intervals[end] = endValue.second;
}
std::map<double, int>::iterator Interval::FindInterval(double value) {
	auto iter = m_Intervals.begin();
	decltype(iter) nextIter;
	while ((nextIter = std::next(iter)) != m_Intervals.end()) {
		if (iter->first <= value && value < nextIter->first) return iter;
		++iter;
	}

	return iter;
}
double Interval::GetMean() const {
	double sum = 0;

	auto iter = m_Intervals.begin();
	decltype(iter) nextIter;
	while ((nextIter = std::next(iter)) != m_Intervals.end()) {
		sum += iter->second * (nextIter->first - iter->first);
		++iter;
	}

	sum += iter->second * (2 * PI - iter->first);
	return sum / (2 * PI);
}

double GetAngle(int x, int y) {
	return std::fmod(std::atan2(y, x) + 2 * PI, 2 * PI);
}