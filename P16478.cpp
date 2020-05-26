#include <iomanip>
#include <iostream>

int main() {
	int pAB, pBC, pCD;
	std::cin >> pAB >> pBC >> pCD;
	std::cout << std::fixed << std::setprecision(6) << static_cast<double>(pAB) * pCD / pBC;
}