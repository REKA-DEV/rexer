#include "rexer/rule/Rule.h"

using namespace rexer;

Rule::Rule(int key) : key(key) {
	// EMPTY
}

RexerResult * Rule::execute(const int id, const string & source, string::size_type start) {
	pair<int, string::size_type> rexerPair = make_pair(id, start);
	shared_ptr<RexerResult> rexerResult;
	
	if (this->rexerResultMap.contains(rexerPair)) {
		rexerResult = this->rexerResultMap[rexerPair];
	} else {
		rexerResult = this->rule(id, source, start);
		this->rexerResultMap[rexerPair] = rexerResult;
	}
	
	return rexerResult.get();
}
