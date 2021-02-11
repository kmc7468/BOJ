#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <string>

struct Node {
	std::map<char, Node*> Nodes;
};

void MakeTree(Node* node, const std::string& word);
int Evaluate(Node* node, int depth);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while (true) {
		Node rootNode;

		int n;
		std::cin >> n;
		if (std::cin.eof()) break;

		for (int i = 0; i < n; ++i) {
			std::string word;
			std::cin >> word;
			MakeTree(&rootNode, word);
		}

		std::cout << std::fixed << std::setprecision(2) << Evaluate(&rootNode, 0) / static_cast<double>(n) << '\n';
	}
}

void MakeTree(Node* node, const std::string& word) {
	for (char c : word) {
		if (node->Nodes[c] == nullptr) {
			node->Nodes[c] = new Node;
		}
		node = node->Nodes[c];
	}
	node->Nodes[0] = nullptr;
}
int Evaluate(Node* node, int depth) {
	int result = 0;
	for (const auto& [c, n] : node->Nodes) {
		if (c == 0) {
			result += depth;
		} else {
			result += Evaluate(n, depth + (depth == 0 || node->Nodes.size() > 1));
		}
	}
	return result;
}