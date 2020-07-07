#include <iostream>
#include <string>

int main() {
	std::string string;
	std::cin >> string;

	for (std::size_t i = 0; i < string.size(); i += 3) {
		const unsigned char uc1 = string[i], uc2 = string[i + 1], uc3 = string[i + 2];
		int cp = ((uc1 & 0x0F) << 12) + ((uc2 & 0x3F) << 6) + (uc3 & 0x3F);

		static constexpr wchar_t chosungs[] =
			{ L'ㄱ', L'ㄲ', L'ㄴ', L'ㄷ', L'ㄸ', L'ㄹ', L'ㅁ', L'ㅂ', L'ㅃ', L'ㅅ', L'ㅆ', L'ㅇ', L'ㅈ', L'ㅉ', L'ㅊ', L'ㅋ', L'ㅌ', L'ㅍ', L'ㅎ' };
		cp = chosungs[(cp - 0xAC00) / 28 / 21];

		std::cout << static_cast<char>((cp >> 12) | 0xE0)
				  << static_cast<char>(((cp >> 6) & 0x3F) | 0x80)
				  << static_cast<char>((cp & 0x3F) | 0x80);
	}
}