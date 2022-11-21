#include "rexer/rule/Multiple.h"

using namespace rexer;

Multiple::Multiple(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, int refKey) : Rule(key), ruleMap(ruleMap), bundle(bundle), refKey(refKey) {
	// EMPTY
}

Multiple::Multiple(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, Rule * refRule) : Rule(key), ruleMap(ruleMap), bundle(bundle), refKey(-1), refRule(refRule) {
	// EMPTY
}

bool Multiple::initiate() {
	if (this->initiated) {
		return this->initiated;
	}
	
	do {
		if (this->refRule != nullptr) {
			this->initiated = true;
			break;
		}
		
		this->refRule = this->ruleMap.find(this->refKey)->second.get();
	} while (false);
	
	this->initiated = this->refRule->initiate();
	
	return this->initiated;
}

shared_ptr<RexerResult> Multiple::rule(int id, const string & source, string::size_type start) {
	// TODO: check initiated
	
	string::size_type end = start;
	vector<shared_ptr<Token>> tokens;
	RexerResult * most = nullptr;
	
	while (end < source.length()) {
		RexerResult * refResult = this->refRule->execute(id, source, end);
		
		if (most == nullptr || (most->end < refResult->most->end)) {
			most = refResult->most;
		}
		
		if (!refResult->success) {
			break;
		}
		
		end = refResult->end;
		copy(refResult->tokens.begin(), refResult->tokens.end(), back_inserter(tokens));
	}
	
	shared_ptr<RexerResult> rexerResult;
	
	if (this->bundle) {
		vector<shared_ptr<Token>> bundled;
		bundled.push_back(make_shared<Token>(this->key, start, end, move(tokens)));
		
		rexerResult = make_shared<RexerResult>(true, start, end, bundled, most);
	} else {
		rexerResult = make_shared<RexerResult>(true, start, end, move(tokens), most);
	}
	
	return rexerResult;
}
