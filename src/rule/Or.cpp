#include "rexer/rule/Or.h"

using namespace rexer;

Or::Or(int key, const map<int, shared_ptr<Rule>> & ruleMap, vector<int> refKeys) : Rule(key), ruleMap(ruleMap), refKeys(move(refKeys)) {
	// EMPTY
}

Or::Or(int key, const map<int, shared_ptr<Rule>> & ruleMap, vector<Rule *> refRules) : Rule(key), ruleMap(ruleMap), refRules(move(refRules)) {
	// EMPTY
}

bool Or::initiate() {
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

shared_ptr<RexerResult> Or::rule(int id, const string & source, string::size_type start) {
	// TODO: check initiated
	
	RexerResult * result = nullptr;
	RexerResult * most = nullptr;
	
	for (Rule * refRule: this->refRules) {
		RexerResult * refResult = refRule->execute(id, source, start);
		
		if (result == nullptr || (refResult->success && (result->end < refResult->end))) {
			result = refResult;
		}
		
		if (most == nullptr || (most->end < refResult->most->end)) {
			most = refResult->most;
		}
	}
	
	return make_shared<RexerResult>(result->success, result->start, result->end, result->tokens, most);
}
