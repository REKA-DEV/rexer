#include "rexer/RexerResult.h"

#include <sstream>

using namespace rexer;

RexerResult::RexerResult(bool success, string::size_type start, string::size_type end) : success(success), start(start), end(end) {
	// EMPTY
}

RexerResult::RexerResult(bool success, string::size_type start, string::size_type end, RexerResult * most) : success(success), start(start), end(end), most(most) {
	// EMPTY
}

RexerResult::RexerResult(bool success, string::size_type start, string::size_type end, vector<shared_ptr<Token>> tokens) : success(success), start(start), end(end), tokens(move(tokens)) {
	// EMPTY
}

RexerResult::RexerResult(bool success, string::size_type start, string::size_type end, vector<shared_ptr<Token>> tokens, RexerResult * most) : success(success), start(start), end(end), tokens(move(tokens)), most(most) {
	// EMPTY
}

string RexerResult::toString() {
	ostringstream stream;
	
	stream << "success: " << this->success << endl;
	stream << "start: " << this->start << endl;
	stream << "end: " << this->end << endl;
	stream << endl;
	
	for (const shared_ptr<Token> & token: this->tokens) {
		stream << token->toString() << endl;
	}
	
	return stream.str();
}
