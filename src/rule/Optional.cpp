#include "rexer/rule/Optional.h"

using namespace rexer;

Optional::Optional(int key, const map<int, shared_ptr<Rule>> & ruleMap, int refKey) : Rule(key), ruleMap(ruleMap), refKey(refKey) {
	// EMPTY
}

Optional::Optional(int key, const map<int, shared_ptr<Rule>> & ruleMap, Rule * refRule) : Rule(key), ruleMap(ruleMap), refKey(-1), refRule(refRule) {
	// EMPTY
}

bool Optional::initiate() {
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

shared_ptr<RexerResult> Optional::rule(int id, const string & source, string::size_type start) noexcept {
	RexerResult * refResult = this->refRule->execute(id, source, start);

	if (refResult->success) {
		return make_shared<RexerResult>(true, refResult->start, refResult->success ? refResult->end : refResult->start, refResult->tokens, refResult->most);
	} else {
		return make_shared<RexerResult>(true, refResult->start, refResult->success ? refResult->end : refResult->start, refResult->most);
	}
}
