#include <iostream>

unsigned char g_Memory[32];
unsigned char g_Adder;
int g_ProgramCounter;

void PrintNumber(unsigned char number);
unsigned char ScanNumber();

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while (true) {
		for (int i = 0; i < 32; ++i) {
			g_Memory[i] = ScanNumber();
			if (!i && std::cin.eof()) return 0;
		}
		g_Adder = 0;
		g_ProgramCounter = 0;

		bool run = true;
		while (run) {
			const unsigned char instruction = g_Memory[g_ProgramCounter] >> 5;
			const unsigned char operand = g_Memory[g_ProgramCounter] & 0b11111;
			g_ProgramCounter = g_ProgramCounter + 1 & 0b11111;

			switch (instruction) {
			case 0b000: g_Memory[operand] = g_Adder; break;
			case 0b001: g_Adder = g_Memory[operand]; break;
			case 0b010: g_ProgramCounter = (!g_Adder ? operand : g_ProgramCounter); break;
			case 0b100: --g_Adder; break;
			case 0b101: ++g_Adder; break;
			case 0b110: g_ProgramCounter = operand; break;
			case 0b111: run = false; break;
			}
		}

		PrintNumber(g_Adder);
	}
}

void PrintNumber(unsigned char number) {
	unsigned char mask = 0b10000000;
	while (mask) {
		std::cout << !!(number & mask);
		mask >>= 1;
	}
	std::cout << '\n';
}
unsigned char ScanNumber() {
	unsigned char result = 0;
	int shift = 8;
	while (shift) {
		char c;
		std::cin >> c;
		result |= (c - '0') << --shift;
	}
	return result;
}