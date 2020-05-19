#include <cassert>
#include <iostream>

void Zero(int a);					// a = 0
void Mov(int from, int to);			// to = from
void And(int a, int b, int c);		// c = a and b
void Or(int a, int b, int c);		// c = a or b
void Xor(int a, int b, int c);		// c = a xor b
void LShift(int a, int b, int c);	// c = a << b
void RShift(int a, int b, int c);	// c = a >> b
void Add(int a, int b, int c);		// c = a + b
void Sub(int a, int b, int c);		// c - a - b
void Not(int a, int b);				// b = ~a
void LNot(int a, int b);			// b = !a
void Neg(int a, int b);				// b = -a

int main() {
	int h, w;
	std::cin >> h >> w;

	std::cout << "INPUT 0\nINPUT 0\n";
	Zero(0);

	// M[0] = 결과
	// M[1~4] = a~d
	// M[5~20] = A0~A15
	for (int n = 0; n < h * w; ++n) {
		std::cout << "INPUT " << n + 5 << '\n';
	}
	std::cout << "INPUT 2\nINPUT 1\nINPUT 4\nINPUT 3\n";

	// M[21~37] = 0~16
	LNot(22, 22);
	for (int i = 2; i <= 16; ++i) {
		Add(21 + i - 1, 22, 21 + i);
	}

	// M[38~53] = 덧셈 여부(0x00000000 또는 0x11111111)
	// M[54] = 임시 메모리
	// M[55] = x좌표
	// M[56] = y좌표
	// M[57] = 임시 메모리
	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			Mov(21, 54);

			// a <= x
			Mov(21 + x, 55);
			Sub(55, 1, 55);
			RShift(55, 32, 55);
			And(55, 22, 55); // MSB
			Or(54, 55, 54);

			// x <= c
			Mov(21 + x, 55);
			Sub(3, 55, 55);
			RShift(55, 32, 55);
			And(55, 22, 55); // MSB
			Or(54, 55, 54);

			// b <= y
			Mov(21 + y, 56);
			Sub(56, 2, 56);
			RShift(56, 32, 56);
			And(56, 22, 56); // MSB
			Or(54, 56, 54);

			// y <= d
			Mov(21 + y, 56);
			Sub(4, 56, 56);
			RShift(56, 32, 56);
			And(56, 22, 56); // MSB
			Or(54, 56, 54);

			Zero(57);
			Not(57, 57);
			Add(57, 54, 57);
			Mov(57, 38 + y * w + x);
		}
	}

	for (int i = 0; i < h * w; ++i) {
		And(5 + i, 38 + i, 54);
		Add(0, 54, 0);
	}

	for (int i = 1; i <= 75; ++i) {
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
	assert(a != b);
	std::cout << "AND 2 " << a << ' ' << b << ' ' << c << '\n';
}
void Or(int a, int b, int c) {
	assert(a != b);
	std::cout << "OR 2 " << a << ' ' << b << ' ' << c << '\n';
}
void Xor(int a, int b, int c) {
	assert(a != b);
	std::cout << "XOR 2 " << a << ' ' << b << ' ' << c << '\n';
}
void LShift(int a, int b, int c) {
	std::cout << "LSHIFT " << a << ' ' << b << ' ' << c << '\n';
}
void RShift(int a, int b, int c) {
	std::cout << "RSHIFT " << a << ' ' << b << ' ' << c << '\n';
}
void Add(int a, int b, int c) {
	// M[61~62] = 피연산자
	Mov(a, 61);
	Mov(b, 62);

	// M[63] = 올림
	for (int i = 0; i < 12; ++i) {
		Xor(61, 62, i + 64);
		And(61, 62, 63);
		LShift(63, 22, 63);
		Mov(i + 64, 61);
		Mov(63, 62);
	}

	// M[64~75] = 덧셈 중간 결과
	Mov(75, c);
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