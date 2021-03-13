#include <iostream>

void PrintTime(int seconds);
int ScanTime();

int main() {
	for (int i = 0; i < 3; ++i) {
		const int in = ScanTime();
		const int out = ScanTime();
		PrintTime(out - in);
	}
}

void PrintTime(int seconds) {
	std::cout << seconds / 3600 << ' ' << seconds % 3600 / 60 << ' ' << seconds % 3600 % 60 << '\n';
}
int ScanTime() {
	int h, m, s;
	std::cin >> h >> m >> s;
	return h * 3600 + m * 60 + s;
}