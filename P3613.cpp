#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

bool IsJava(const std::string& identifier);
std::string ToCpp(const std::string& identifier);
bool IsCpp(const std::string& identifier);
std::string ToJava(const std::string& identifier);

int main() {
	std::string identifier;
	std::cin >> identifier;

	if (IsJava(identifier)) {
		std::cout << ToCpp(identifier);
	} else if (IsCpp(identifier)) {
		std::cout << ToJava(identifier);
	} else if (std::islower(identifier.front())) {
		std::cout << identifier;
	} else {
		std::cout << "Error!";
	}
}

bool IsJava(const std::string& identifier) {
	return std::find_if(identifier.begin(), identifier.end(), [](char c) {
		return !!std::isupper(c);
	}) != identifier.end();
}
std::string ToCpp(const std::string& identifier) {
	if (std::isupper(identifier.front())) return "Error!";

	std::string result;
	for (char c : identifier) {
		if (c == '_') return "Error!";
		else if (std::isupper(c)) {
			result.push_back('_');
			result.push_back(std::tolower(c));
		} else {
			result.push_back(c);
		}
	}
	return result;
}
bool IsCpp(const std::string& identifier) {
	return identifier.find('_') != std::string::npos;
}
std::string ToJava(const std::string& identifier) {
	if (identifier.front() == '_') return "Error!";
	else if (identifier.back() == '_') return "Error!";

	std::string result;
	bool toUpper = false;
	for (char c : identifier) {
		if (c == '_') {
			if (toUpper) return "Error!";
			toUpper = true;
		} else if (toUpper) {
			toUpper = false;
			result.push_back(std::toupper(c));
		} else {
			result.push_back(c);
		}
	}
	return result;
}