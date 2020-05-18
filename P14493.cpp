#include <iostream>
#include <vector>

struct Bot {
	int A, B;
};

std::istream& operator>>(std::istream& stream, Bot& bot);

int main() {
	int n;
	std::cin >> n;

	std::vector<Bot> bots(n);
	for (Bot& bot : bots) {
		std::cin >> bot;
	}

	int seconds = 0;
	for (const Bot& bot : bots) {
		if (seconds % (bot.A + bot.B) < bot.B) {
			seconds += bot.B - seconds % (bot.A + bot.B);
		}
		++seconds;
	}
	std::cout << seconds;
}

std::istream& operator>>(std::istream& stream, Bot& bot) {
	return stream >> bot.A >> bot.B;
}