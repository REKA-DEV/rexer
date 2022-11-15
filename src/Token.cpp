#include "rexer/Token.h"

#include <sstream>

using namespace rexer;

Token::Token(int key, string::size_type start, string::size_type end, string value) : key(key), start(start), end(end), value(move(value)) {
	// EMPTY
}

Token::Token(int key, string::size_type start, string::size_type end, vector<shared_ptr<Token>> children) : key(key), start(start), end(end), children(move(children)) {
	// EMPTY
}

string Token::toString() {
	return this->toString(0);
}

string Token::toString(int depth) {
	ostringstream stream;
	
	for (int i = 0; i < depth; i++) {
		stream << "  ";
	}
	
	stream << this->key << " ";
	
	if (this->value.empty()) {
		stream << "(" << this->start << " " << this->end << " " << this->children.size() << ")";
	} else {
		stream << this->value << " (" << this->start << " " << this->end << ")";
	}
	
	stream << endl;
	
	for (const shared_ptr<Token> & token: this->children) {
		stream << token->toString(depth + 1);
	}
	
	return stream.str();
}
