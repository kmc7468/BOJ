#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

int Map(char c);
double ReadReal(const std::string& question, std::size_t index);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	std::cin.get();

	std::cout << std::fixed << std::setprecision(2);
	for (int i = 0; i < n; ++i) {
		std::string question;
		std::getline(std::cin, question);

		const std::size_t firstEqual = question.find('='), secondEqual = question.find('=', firstEqual + 1);
		const char first = question[firstEqual - 1], second = question[secondEqual - 1];

		double array[3]{ -1, -1, -1 };
		array[Map(first)] = ReadReal(question, firstEqual + 1);
		array[Map(second)] = ReadReal(question, secondEqual + 1);

		std::cout << "Problem #" << i + 1 << '\n';
		if (array[0] == -1) {
			std::cout << "P=" << array[1] * array[2] << "W\n\n";
		} else if (array[1] == -1) {
			std::cout << "U=" << array[0] / array[2] << "V\n\n";
		} else {
			std::cout << "I=" << array[0] / array[1] << "A\n\n";
		}
	}
}

int Map(char c) {
	switch (c) {
	case 'P': return 0;
	case 'U': return 1;
	case 'I': return 2;
	}
}
double ReadReal(const std::string& question, std::size_t index) {
	char* end;
	const double value = std::strtod(question.c_str() + index, &end);
	switch (*end) {
	case 'm': return value / 1000;
	case 'k': return value * 1000;
	case 'M': return value * 1000 * 1000;
	default: return value;
	}
}