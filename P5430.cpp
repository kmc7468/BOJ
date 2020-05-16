#include <ios>
#include <iostream>

char g_Function[100'000 + 1];
int g_Array[100'000], g_Count;
int g_Begin, g_End;
int g_Delta = 1;

void PrintArray();
void ScanArray();

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> g_Function;
		ScanArray();

		bool isError = false;
		const char* command = g_Function;
		while (*command) {
			const char c = *command++;
			if (c == 'R') {
				g_Delta = -g_Delta;
			} else {
				if (g_Begin == g_End) {
					std::cout << "error\n";
					isError = true;
					break;
				}

				if (g_Delta >= 0) {
					++g_Begin;
				} else {
					--g_End;
				}
			}
		}

		if (!isError) {
			PrintArray();
		}
	}
}

void PrintArray() {
	std::cout << '[';

	const int* begin;
	const int* end;
	if (g_Delta >= 0) {
		begin = g_Array + g_Begin;
		end = g_Array + g_End;
	} else {
		begin = g_Array + g_End - 1;
		end = g_Array + g_Begin - 1;
	}

	bool isFirst = true;
	while (begin != end) {
		if (isFirst) {
			isFirst = false;
		} else {
			std::cout << ',';
		}
		std::cout << *begin;
		begin += g_Delta;
	}

	std::cout << "]\n";
}
void ScanArray() {
	std::cin >> g_Count;
	g_Begin = 0;
	g_End = g_Count;
	g_Delta = 1;

	char dummy;
	std::cin >> dummy;
	for (int i = 0; i < g_Count; ++i) {
		if (i) {
			std::cin >> dummy;
		}
		std::cin >> g_Array[i];
	}
	std::cin >> dummy;
}