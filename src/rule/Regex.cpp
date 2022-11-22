#include "rexer/rule/Regex.h"

using namespace rexer;

Regex::Regex(int key, const map<int, shared_ptr<Rule>> & ruleMap, regex reg) : Rule(key), reg(move(reg)) {
	// EMPTY
}

bool Regex::initiate() {
	this->initiated = true;
	return this->initiated;
}

shared_ptr<RexerResult> Regex::rule(int id, const string & source, string::size_type start) noexcept {
	bool success = false;
	string::size_type end = start;
	vector<shared_ptr<Token>> tokens;
	
	do {
		if (source.length() <= start) {
			break;
		}
		
		auto iterator = sregex_iterator(source.begin() + start, source.end(), this->reg);
		
		if (iterator->empty()) {
			break;
		}
		
		auto position = iterator->position();
		auto length = iterator->length();
		
		if (0 != position) {
			break;
		}
		
		success = true;
		end = end + length;
		tokens.push_back(make_shared<Token>(this->key, start, end, source.substr(start, length)));
	} while (false);
	
	shared_ptr<RexerResult> rexerResult = make_shared<RexerResult>(success, start, end, move(tokens));
	rexerResult->most = rexerResult.get();
	
	return rexerResult;
}
