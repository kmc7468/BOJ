#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

enum NodeType {
	NODE_ROOT,
	NODE_ADDSUB,
	NODE_MULDIV,
	NODE_PAREN,
	NODE_CHAR,
};

struct Node final {
	NodeType Type;
	std::vector<Node*> Children;
	char Character;
	char Connecter;

	Node() noexcept = default;
	Node(Node&& node) noexcept;
	~Node();

	Node& operator=(Node&& node) noexcept;
};

std::ostream& operator<<(std::ostream& stream, const Node& node);

char GetChar(const std::string& string, std::size_t index);
bool AddSub(const std::string& string, std::size_t& index, Node* node);
bool MulDiv(const std::string& string, std::size_t& index, Node* node);
bool Paren(const std::string& string, std::size_t& index, Node* node);
bool Char(const std::string& string, std::size_t& index, Node* node);

bool IsNegativeConnecter(char c);
void RemoveNestedParens(Node* node);
void RemoveParens(Node* node, Node* parent, std::size_t& index);

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::string expression;
		std::cin >> expression;

		Node tree;
		tree.Type = NODE_ROOT;
		Node* root = tree.Children.emplace_back(new Node());

		std::size_t j = 0;
		AddSub(expression, j, root);
		RemoveParens(root, &tree, j = 0);

		root = tree.Children[0];
		if (root->Type == NODE_PAREN) {
			root = root->Children[0];
		}
		std::cout << *root << '\n';
	}
}

Node::Node(Node&& node) noexcept
	: Type(node.Type), Children(std::move(node.Children)), Character(node.Character), Connecter(node.Connecter) {}
Node::~Node() {
	for (Node* child : Children) {
		delete child;
	}
}

Node& Node::operator=(Node&& node) noexcept {
	Type = node.Type;
	Children = std::move(node.Children);
	Character = node.Character;
	Connecter = node.Connecter;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Node& node) {
	switch (node.Type) {
	case NODE_ADDSUB:
	case NODE_MULDIV:
		stream << *node.Children[0];
		for (std::size_t i = 1; i < node.Children.size(); ++i) {
			stream << node.Children[i]->Connecter << *node.Children[i];
		}
		break;

	case NODE_PAREN:
		stream << '(' << *node.Children[0] << ')';
		break;

	case NODE_CHAR:
		stream << node.Character;
		break;
	}
	return stream;
}

char GetChar(const std::string& string, std::size_t index) {
	if (index < string.size()) return string[index];
	else return 0;
}
bool AddSub(const std::string& string, std::size_t& index, Node* node) {
	Node* const lhs = new Node();
	MulDiv(string, index, lhs);

	char oper = GetChar(string, index);
	if (oper == '+' || oper == '-') {
		node->Type = NODE_ADDSUB;
		node->Children.push_back(lhs);
		do {
			const char connecter = string[index];
			Node* const rhs = node->Children.emplace_back(new Node());
			MulDiv(string, ++index, rhs);
			rhs->Connecter = connecter;
			oper = GetChar(string, index);
		} while (oper == '+' || oper == '-');
	} else {
		*node = std::move(*lhs);
		delete lhs;
	}

	return true;
}
bool MulDiv(const std::string& string, std::size_t& index, Node* node) {
	Node* const lhs = new Node();
	Paren(string, index, lhs);

	char oper = GetChar(string, index);
	if (oper == '*' || oper == '/') {
		node->Type = NODE_MULDIV;
		node->Children.push_back(lhs);
		do {
			const char connecter = string[index];
			Node* const rhs = node->Children.emplace_back(new Node());
			Paren(string, ++index, rhs);
			rhs->Connecter = connecter;
			oper = GetChar(string, index);
		} while (oper == '*' || oper == '/');
	} else {
		*node = std::move(*lhs);
		delete lhs;
	}

	return true;
}
bool Paren(const std::string& string, std::size_t& index, Node* node) {
	if (GetChar(string, index) == '(') {
		node->Type = NODE_PAREN;
		Node* const child = node->Children.emplace_back(new Node());
		AddSub(string, ++index, child);
		return ++index;
	} else return Char(string, index, node);
}
bool Char(const std::string& string, std::size_t& index, Node* node) {
	if (std::islower(GetChar(string, index))) {
		node->Type = NODE_CHAR;
		node->Character = string[index++];
		return true;
	} else return false;
}

bool IsNegativeConnecter(char c) {
	return c == '-' || c == '/';
}
void RemoveNestedParens(Node* node) {
	if (node->Children[0]->Type == NODE_PAREN) {
		std::vector<Node*> nesteds;
		Node* child = node->Children[0];
		while (child->Type == NODE_PAREN) {
			nesteds.push_back(child);
			Node* const parent = child;
			child = parent->Children[0];
			parent->Children.clear();
		}

		node->Children[0] = child;
		for (Node* const nested : nesteds) {
			delete nested;
		}
	}
}
void RemoveParens(Node* node, Node* parent, std::size_t& index) {
	if (node->Type == NODE_PAREN) {
		RemoveNestedParens(node);

		Node* const child = node->Children[0];
		for (std::size_t i = 0; i < child->Children.size(); ++i) {
			RemoveParens(child->Children[i], child, i);
		}

		const char connecter = node->Connecter;
		if (child->Type == NODE_CHAR || parent->Type == NODE_ADDSUB && child->Type == NODE_MULDIV) {
			parent->Children[index] = child;
			child->Connecter = connecter;

			index -= child->Type == NODE_CHAR;
			node->Children.clear();
			delete node;
		} else if (parent->Type == child->Type && !IsNegativeConnecter(connecter)) {
			parent->Children.erase(parent->Children.begin() + index);
			parent->Children.insert(parent->Children.begin() + index, child->Children.begin(), child->Children.end());
			child->Children[0]->Connecter = connecter;

			--index;
			child->Children.clear();
			delete node;
		br:;
		}
	} else {
		for (std::size_t i = 0; i < node->Children.size(); ++i) {
			RemoveParens(node->Children[i], node, i);
		}
	}
}