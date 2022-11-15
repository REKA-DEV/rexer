#include "rexer/rule/Word.h"

using namespace rexer;

Word::Word(int key, string word) : Rule(key), word(move(word)), length(this->word.length()) {
	// EMPTY
}

bool Word::initiate() {
	this->initiated = true;
	return this->initiated;
}

shared_ptr<RexerResult> Word::rule(int id, const string & source, string::size_type start) {
	// TODO: check initiated
	
	bool success = false;
	string::size_type end = start + this->length;
	vector<shared_ptr<Token>> tokens;
	
	do {
		if (source.length() < end) {
			break;
		}
		
		if (source.find(this->word, start) != start) {
			break;
		}
		
		success = true;
		tokens.push_back(make_shared<Token>(this->key, start, end, source.substr(start, this->length)));
	} while (false);
	
	shared_ptr<RexerResult> rexerResult = make_shared<RexerResult>(success, start, end, move(tokens));
	rexerResult->most = rexerResult.get();
	
	return rexerResult;
}
