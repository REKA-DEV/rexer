#include "rexer/rule/Or.h"

using namespace rexer;

Or::Or(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, vector<int> refKeys) : Rule(key), ruleMap(ruleMap), bundle(bundle), refKeys(move(refKeys)) {
	// EMPTY
}

Or::Or(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, vector<Rule *> refRules) : Rule(key), ruleMap(ruleMap), bundle(bundle), refRules(move(refRules)) {
	// EMPTY
}

bool Or::initiate() {
	do {
		if (this->initiated) {
			break;
		}
		
		if (!this->refRules.empty()) {
			this->initiated = true;
			break;
		}
		
		bool initiating = true;
		
		for (auto & iterator : this->refKeys) {
			Rule * rule = this->ruleMap.find(iterator)->second.get();
			initiating = initiating && rule->initiate();
			this->refRules.push_back(rule);
		}
		
		this->initiated = initiating;
	} while (false);
	
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
