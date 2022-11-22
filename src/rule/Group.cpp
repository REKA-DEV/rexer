#include "rexer/rule/Group.h"

using namespace rexer;

Group::Group(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, vector<int> refKeys) : Rule(key), ruleMap(ruleMap), bundle(bundle), refKeys(move(refKeys)) {
	// EMPTY
}

Group::Group(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, vector<Rule *> refRules) : Rule(key), ruleMap(ruleMap), bundle(bundle), refRules(move(refRules)) {
	// EMPTY
}

bool Group::initiate() {
	if (this->initiated) {
		return this->initiated;
	}
	
	do {
		if (!this->refRules.empty()) {
			break;
		}
		
		for (int refKey : this->refKeys) {
			this->refRules.push_back(this->ruleMap.find(refKey)->second.get());
		}
	} while (false);
	
	this->initiated = true;
	
	for (Rule * refRule : this->refRules) {
		this->initiated = this->initiated && refRule->initiate();
	}
	
	return this->initiated;
}

shared_ptr<RexerResult> Group::rule(int id, const string & source, string::size_type start) noexcept {
	bool success = true;
	string::size_type end = start;
	vector<shared_ptr<Token>> tokens;
	RexerResult * most = nullptr;
	
	for (Rule * refRule: this->refRules) {
		RexerResult * refResult = refRule->execute(id, source, end);
		
		
		if (most == nullptr || (most->end < refResult->most->end)) {
			most = refResult->most;
		}
		
		if (!refResult->success) {
			success = false;
			break;
		}
		
		end = refResult->end;
		copy(refResult->tokens.begin(), refResult->tokens.end(), back_inserter(tokens));
	}
	
	shared_ptr<RexerResult> rexerResult;
	
	if (this->bundle) {
		vector<shared_ptr<Token>> bundled;
		bundled.push_back(make_shared<Token>(this->key, start, end, move(tokens)));
		
		rexerResult = make_shared<RexerResult>(success, start, end, bundled, most);
	} else {
		rexerResult = make_shared<RexerResult>(success, start, end, move(tokens), most);
	}
	
	return rexerResult;
}
