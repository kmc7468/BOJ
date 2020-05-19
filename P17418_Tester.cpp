/*
 * (C) 2020. kmc7468 All rights reserved.
 *
 * 이 프로그램은 백준 17418번 문제(G++ Language)를 풀 때, 생성된 G++ 코드를 테스트하는 목적 외에는 사용하지 마세요.
 * 파일 수정 후 재배포를 엄격히 금지합니다. 파일 수정 없이 재배포를 하는 것은 허용됩니다.
 * 문제 풀이 후 테스트 목적으로 코드를 수정하는 것은 허용됩니다.
 *
 * 사용법: ./P17418_Tester.exe <실행할 G++ 코드가 저장된 경로>
 * 사용시 주의사항:
 * 1) G++ 코드는 UTF-16 LE로 인코딩되어 있어야 합니다.
 * 2) G++ 코드는 문법적으로 문제가 없어야 합니다.
 * 3) AND, OR, XOR 명령어의 경우 2개의 피연산자에 대해서만 연산할 수 있습니다.
 * 4) 메모리 범위 검사를 하지 않습니다.
 * 사용팁:
 * 1) G++ 코드에 세미콜론으로 시작하는 줄은 주석 처리되며, 주석의 메세지가 표시됩니다.
 * 2) 문제를 풀이하는 프로그램의 표준 출력을 파일로 리다이렉트하면 더 편리합니다.
 */

#include <codecvt>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <locale>
#include <iostream>
#include <string>

int g_Memory[1000];
unsigned g_CodeCount = 0, g_MemoryAccessCount = 0;

#ifndef _WIN32
#	error Windows에서만 컴파일할 수 있습니다.
#endif

int main(int argc, char* argv[]) {
	std::wcout.imbue(std::locale(""));

	if (argc == 1) {
		std::wcout << L"실행할 G++ 코드의 경로가 필요합니다.\n";
		return EXIT_FAILURE;
	}

	std::wifstream code(argv[1]);
	if (!code) {
		std::wcout << L"G++ 코드를 열지 못했습니다.\n";
		return EXIT_FAILURE;
	}

	code.imbue(std::locale(code.getloc(), new std::codecvt_utf16<wchar_t, 0xFFFF, std::little_endian>));
	code.seekg(2, std::wifstream::cur);

	std::wstring line;
	while (std::getline(code, line) && ++g_CodeCount) {
		std::size_t spaceOffsets[5]{ 0 };
		for (int i = 1; i <= 4; ++i) {
			spaceOffsets[i] = line.find(' ', spaceOffsets[i - 1] + 1);
		}
		const std::wstring mnemonic = line.substr(0, spaceOffsets[1]);

		if (!mnemonic.size()) continue;
		else if (mnemonic.front() == L';') {
			std::wcout << L"Comment: " << line.substr(1);
			continue;
		}

		const int firstArgument = std::stoi(line.substr(spaceOffsets[1] + 1, spaceOffsets[2] - spaceOffsets[1]));
		++g_MemoryAccessCount;
		if (mnemonic == L"INPUT") {
			std::cin >> g_Memory[firstArgument];
			continue;
		}

		const int secondArgument = std::stoi(line.substr(spaceOffsets[2] + 1, spaceOffsets[3] - spaceOffsets[2]));
		++g_MemoryAccessCount;
		if (mnemonic == L"NOT") {
			g_Memory[secondArgument] = !g_Memory[firstArgument];
			continue;
		} else if (mnemonic == L"BNOT") {
			g_Memory[secondArgument] = ~g_Memory[firstArgument];
			continue;
		}

		const int thirdArgument = std::stoi(line.substr(spaceOffsets[3] + 1, spaceOffsets[4] - spaceOffsets[3]));
		++g_MemoryAccessCount;
		if (mnemonic == L"LSHIFT") {
			g_Memory[thirdArgument] = (g_Memory[firstArgument] << g_Memory[secondArgument]);
			continue;
		} else if (mnemonic == L"RSHIFT") {
			g_Memory[thirdArgument] = (g_Memory[firstArgument] >> g_Memory[secondArgument]);
			continue;
		}

		const int fourthArgument = std::stoi(line.substr(spaceOffsets[4] + 1));
		if (mnemonic == L"AND") {
			if (firstArgument != 2) {
				std::wcout << L"Warning: AND 명령어는 피연산자를 2개만 가질 수 있습니다.\n";
			}
			g_Memory[fourthArgument] = (g_Memory[secondArgument] & g_Memory[thirdArgument]);
			continue;
		} else if (mnemonic == L"OR") {
			if (firstArgument != 2) {
				std::wcout << L"Warning: OR 명령어는 피연산자를 2개만 가질 수 있습니다.\n";
			}
			g_Memory[fourthArgument] = (g_Memory[secondArgument] | g_Memory[thirdArgument]);
			continue;
		} else if (mnemonic == L"XOR") {
			if (firstArgument != 2) {
				std::wcout << L"Warning: XOR 명령어는 피연산자를 2개만 가질 수 있습니다.\n";
			}
			g_Memory[fourthArgument] = (g_Memory[secondArgument] ^ g_Memory[thirdArgument]);
			continue;
		}

		std::wcout << L"Warning: " << mnemonic << L"명령어는 존재하지 않는 명령어입니다.\n";
	}

	for (int i = 1; i < 1000; ++i) {
		if (g_Memory[i]) {
			std::wcout << L"Warning: " << i << "번 메모리의 값이 코드 실행이 완료된 후에도 0이 아닙니다.\n";
		}
	}
	std::wcout << L"S = " << g_Memory[0] << L'\n';
	std::wcout << L"(코드 총 " << g_CodeCount << L"회 실행, 메모리 총 " << g_MemoryAccessCount << L"회 접근)\n";
}