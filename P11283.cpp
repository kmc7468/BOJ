#include <iostream>
#include <locale>

int main() {
	std::locale::global(std::locale(""));

	wchar_t hangul;
	std::wcin >> hangul;
	std::wcout << static_cast<int>(hangul - L'가' + 1);
}