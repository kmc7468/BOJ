#include <iostream>
#include <memory>

int main() {
	int width, height;
	std::cin >> height >> width;

	const int realWidth = width + 1;
	const int resizedWidth = width * 2;
	const int realResizedWidth = resizedWidth + 1;

	std::unique_ptr<char[]> org(new char[realWidth * height + 1]{ 0 });
	for (int h = 0; h < height; ++h) {
		std::cin >> &org[h * realWidth];
		org[(h + 1) * realWidth - 1] = '\n';
	}

	std::unique_ptr<char[]> resized(new char[realResizedWidth * height + 1]{ 0 });
	for (int h = 0; h < height; ++h) {
		std::cin >> &resized[h * realResizedWidth];
		resized[(h + 1) * realResizedWidth - 1] = '\n';
	}

	for (int h = 0; h < height; ++h) {
		for (int w = 0; w < width; ++w) {
			const char c = org[h * realWidth + w];
			if (c != resized[h * realResizedWidth + w * 2] ||
				c != resized[h * realResizedWidth + w * 2 + 1]) {
				std::cout << "Not Eyfa";
				return 0;
			}
		}
	}

	std::cout << "Eyfa";
}