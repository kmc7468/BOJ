#include <iostream>

void Zero(int a);
void Mov(int from, int to);
void And(int a, int b, int c);
void Or(int a, int b, int c);
void Xor(int a, int b, int c);
void LShift(int a, int b, int c);
void RShift(int a, int b, int c);
void Add(int a, int b, int c);
void Sub(int a, int b, int c);
void Not(int a, int b);
void LNot(int a, int b);
void Neg(int a, int b);
void Less(int a, int b, int c);

int main() {
	int h, w;
	std::cin >> h >> w;

	std::cout << "INPUT 0\nINPUT 0\n";
	Zero(0);

	for (int n = 0; n < h * w; ++n) {
		std::cout << "INPUT " << n + 5 << '\n';
	}
	std::cout << "INPUT 2\nINPUT 1\nINPUT 4\nINPUT 3\n";

	LNot(22, 22);
	for (int i = 2; i <= 16; ++i) {
		Add(21 + i - 1, 22, 21 + i);
	}

	for (int y = 0; y < h; ++y) {
		Mov(21 + y, 56);
		for (int x = 0; x < w; ++x) {
			Mov(21, 54);
			Mov(21 + x, 55);

			Less(55, 1, 54);
			Less(3, 55, 54);
			Less(56, 2, 54);
			Less(4, 56, 54);

			const int i = 38 + y * w + x;
			Not(i, i);
			Add(i, 54, i);
		}
	}

	for (int i = 0; i < h * w; ++i) {
		And(5 + i, 38 + i, 54);
		Add(0, 54, 0);
	}

	for (int i = 1; i <= 64; ++i) {
		if (i == 21) continue;
		Zero(i);
	}
}

void Zero(int a) {
	And(a, 21, a);
}
void Mov(int from, int to) {
	Not(from, 59);
	Not(59, to);
}
void And(int a, int b, int c) {
	std::cout << "AND 2 " << a << ' ' << b << ' ' << c << '\n';
}
void Or(int a, int b, int c) {
	std::cout << "OR 2 " << a << ' ' << b << ' ' << c << '\n';
}
void Xor(int a, int b, int c) {
	std::cout << "XOR 2 " << a << ' ' << b << ' ' << c << '\n';
}
void LShift(int a, int b, int c) {
	std::cout << "LSHIFT " << a << ' ' << b << ' ' << c << '\n';
}
void RShift(int a, int b, int c) {
	std::cout << "RSHIFT " << a << ' ' << b << ' ' << c << '\n';
}
void Add(int a, int b, int c) {
	Mov(a, 61);
	Mov(b, 62);

	for (int i = 0; i < 12; ++i) {
		Xor(61, 62, 64);
		And(61, 62, 63);
		LShift(63, 22, 63);
		Mov(64, 61);
		Mov(63, 62);
	}

	Mov(64, c);
	Zero(63);
}
void Sub(int a, int b, int c) {
	Mov(b, 60);
	Neg(60, 60);
	Add(a, 60, c);
}
void Not(int a, int b) {
	std::cout << "BNOT " << a << ' ' << b << '\n';
}
void LNot(int a, int b) {
	std::cout << "NOT " << a << ' ' << b << '\n';
}
void Neg(int a, int b) {
	Not(a, 59);
	Add(59, 22, b);
}
void Less(int a, int b, int c) {
	Mov(a, 58);
	Sub(58, b, 58);
	RShift(58, 32, 58);
	And(58, 22, 58);
	Or(c, 58, c);
}