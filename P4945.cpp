#include <cctype>
#include <cstddef>
#include <deque>
#include <iostream>
#include <ios>
#include <string>
#include <utility>
#include <vector>

enum NodeType {
	NODE_ROOT,
	NODE_ADD,
	NODE_SUB,
	NODE_MUL,
	NODE_DIV,
	NODE_NEG,
	NODE_POW,
	NODE_PAREN,
	NODE_DIGIT,
};

enum Rank {
	RANK_NONE,
	RANK_MUL,
};

class Node final {
public:
	NodeType Type = NODE_ROOT;
	Node* Left = nullptr;
	Node* Right = nullptr;
	int Value = 0;

public:
	Node() noexcept = default;
	Node(NodeType type, int value) noexcept;
	Node(NodeType type, Node* left) noexcept;
	Node(Node&& node) noexcept;
	~Node();

public:
	Node& operator=(Node&& node) noexcept;
	bool operator==(const Node&) = delete;
	bool operator!=(const Node&) = delete;

public:
	int Eval() const;
};

int Remainder(int a, int b);

std::size_t FindBase(const std::vector<std::string>& lines, std::size_t begin, std::size_t end, std::size_t index);
void Parse(const std::vector<std::string>& lines, std::size_t top, std::size_t bottom, std::size_t base,
	std::deque<Node*>& deque, std::size_t& i, std::size_t end, Node* node, Rank rank = RANK_NONE);
Node* ParsePow(Node* orgNode, const std::vector<std::string>& lines, std::size_t top, std::size_t bottom, std::size_t base,
	std::size_t& i, std::size_t end, Node* node);
void PushOperand(std::deque<Node*>& deque, bool& requiredRhs, Node* node);

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while (true) {
		int n;
		std::cin >> n;
		if (n == 0) break;

		std::vector<std::string> lines(n);
		for (std::string& line : lines) {
			std::cin >> line;
		}

		Node tree;
		tree.Left = new Node();

		std::deque<Node*> deque;
		std::size_t i = 0;
		Parse(lines, 0, n, FindBase(lines, 0, n, 0), deque, i, lines.front().size(), tree.Left);

		std::cout << tree.Eval() << '\n';
	}
}

Node::Node(Node&& node) noexcept
	: Type(node.Type), Left(node.Left), Right(node.Right), Value(node.Value) {
	node.Left = node.Right = nullptr;
}
Node::Node(NodeType type, int value) noexcept
	: Type(type), Value(value) {}
Node::Node(NodeType type, Node* left) noexcept
	: Type(type), Left(left) {}
Node::~Node() {
	delete Left;
	delete Right;
}

Node& Node::operator=(Node&& node) noexcept {
	Type = node.Type;
	(delete Left, Left) = node.Left;
	(delete Right, Right) = node.Right;
	Value = node.Value;

	node.Left = nullptr;
	node.Right = nullptr;
	return *this;
}

int Node::Eval() const {
	int result = 1;
	switch (Type) {
	case NODE_ROOT: result = Left->Eval(); break;
	case NODE_ADD: result = Left->Eval() + Right->Eval(); break;
	case NODE_SUB: result = Left->Eval() - Right->Eval(); break;
	case NODE_MUL: result = Left->Eval() * Right->Eval(); break;
	case NODE_DIV: {
		const int right = Right->Eval();
		for (int i = 1; i < 2011; ++i) {
			if (Remainder(right * i, 2011) == 1) {
				result = Left->Eval() * i;
				break;
			}
		}
		break;
	}
	case NODE_NEG: result = -Right->Eval(); break;
	case NODE_POW: {
		const int left = Left->Eval(), right = Right->Eval();
		for (int i = 0; i < right; ++i) {
			result = Remainder(result * left, 2011);
		}
		break;
	}
	case NODE_PAREN: result = Left->Eval(); break;
	case NODE_DIGIT: result = Value; break;
	}
	return Remainder(result, 2011);
}

int Remainder(int a, int b) {
	return (a % b + b) % b;
}

std::size_t FindBase(const std::vector<std::string>& lines, std::size_t begin, std::size_t end, std::size_t index) {
	if (index >= lines.front().size()) return static_cast<std::size_t>(-1);

	for (std::size_t i = begin; i < end; ++i) {
		if (lines[i][index] != '.') return i;
	}
	return static_cast<std::size_t>(-1);
}
void Parse(const std::vector<std::string>& lines, std::size_t top, std::size_t bottom, std::size_t base,
	std::deque<Node*>& deque, std::size_t& i, std::size_t end, Node* node, Rank rank) {
	const std::string& line = lines[base];
	bool requiredRhs = false;

	char prev = 0;
	for (; i < end; ++i) {
		const char c = line[i];
		if (c == '.') {
			if (i && prev == '.') {
				--i;
				break;
			} else {
				prev = '.';
				continue;
			}
		} else if (std::isdigit(c)) {
			Node* const digitNode = new Node(NODE_DIGIT, c - '0');
			Node* const resultNode = ParsePow(digitNode, lines, top, bottom, base, ++i, end, node);
			PushOperand(deque, requiredRhs, resultNode);
		} else if (c == '+') {
			if (rank >= RANK_MUL) {
				--i;
				break;
			}
			deque.back() = new Node(NODE_ADD, deque.back());
			requiredRhs = true;
		} else if (c == '-') {
			if (line[i + 1] == '-') {
				Node* const divNode = new Node(NODE_DIV, nullptr);

				std::size_t lastMinus = i + 2;
				while (lastMinus < end && line[lastMinus] == '-') {
					++lastMinus;
				}

				std::size_t topBegin = i, bottomBegin = i;
				while (FindBase(lines, top, base, topBegin) == -1) {
					++topBegin;
				}
				while (FindBase(lines, base + 1, bottom, bottomBegin) == -1) {
					++bottomBegin;
				}

				std::deque<Node*> newDeque;
				Parse(lines, top, base, FindBase(lines, top, base, topBegin), newDeque, i = topBegin, lastMinus, divNode->Left = new Node());
				Parse(lines, base + 1, bottom, FindBase(lines, base + 1, bottom, bottomBegin), newDeque, i = bottomBegin, lastMinus, divNode->Right = new Node());
				i = lastMinus;

				Node* const resultNode = ParsePow(divNode, lines, top, bottom, base, i, end, node);
				PushOperand(deque, requiredRhs, resultNode);
			} else if (requiredRhs || deque.empty()) {
				Node* const negNode = new Node(NODE_NEG, nullptr);
				if (!deque.empty()) {
					deque.back()->Right = negNode;
				}
				deque.push_back(negNode);
				requiredRhs = true;
			} else if (rank >= RANK_MUL) {
				--i;
				break;
			} else {
				deque.back() = new Node(NODE_SUB, deque.back());
				requiredRhs = true;
			}
		} else if (c == '*') {
			if (rank < RANK_MUL) {
				const NodeType type = deque.back()->Type;
				if (type == NODE_ADD || type == NODE_SUB) {
					deque.push_back(deque.back()->Right);
					Parse(lines, top, bottom, base, deque, i, end, deque[deque.size() - 2]->Right = new Node(), RANK_MUL);
				} else {
					Node* const mulNode = new Node();
					Parse(lines, top, bottom, base, deque, i, end, mulNode, RANK_MUL);
					deque.push_back(mulNode);
				}
			} else {
				deque.back() = new Node(NODE_MUL, deque.back());
				requiredRhs = true;
			}
		} else if (c == '(') {
			Node* const parenNode = new Node(NODE_PAREN, new Node());
			std::deque<Node*> newDeque;
			Parse(lines, top, bottom, base, newDeque, i += 2, end, parenNode->Left);
			Node* const resultNode = ParsePow(parenNode, lines, top, bottom, base, i, end, node);
			PushOperand(deque, requiredRhs, resultNode);
		} else if (c == ')') {
			if (rank == RANK_MUL) {
				--i;
			} else {
				++i;
			}
			break;
		}

		if (i < line.size()) {
			prev = line[i];
		}
	}

	*node = std::move(*deque.back());
	delete deque.back();
	deque.pop_back();
}
Node* ParsePow(Node* orgNode, const std::vector<std::string>& lines, std::size_t top, std::size_t bottom, std::size_t base,
	std::size_t& i, std::size_t end, Node* node) {
	const std::size_t powStart = FindBase(lines, top, base, i);
	if (powStart != -1) {
		Node* const powNode = new Node(NODE_POW, orgNode);
		std::deque<Node*> deque;
		Parse(lines, top, base, powStart, deque, i, end, powNode->Right = new Node());
		return powNode;
	} else return orgNode;
}
void PushOperand(std::deque<Node*>& deque, bool& requiredRhs, Node* node) {
	if (requiredRhs) {
		deque.back()->Right = node;
		while (deque.size() > 1 && deque.back()->Type == NODE_NEG) {
			deque.pop_back();
		}
		requiredRhs = false;
	} else {
		deque.push_back(node);
	}
}