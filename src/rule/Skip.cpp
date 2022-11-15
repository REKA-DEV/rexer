#include "rexer/rule/Skip.h"

using namespace rexer;

Skip::Skip(const map<int, shared_ptr<Rule>> & ruleMap, int key, int refKey) : Rule(key), ruleMap(ruleMap), refKey(refKey) {
	// EMPTY
}

Skip::Skip(const map<int, shared_ptr<Rule>> & ruleMap, int key, Rule * refRule) : Rule(key), ruleMap(ruleMap), refKey(-1), refRule(refRule) {
	// EMPTY
}

bool Skip::initiate() {
	do {
		if (this->initiated) {
			break;
		}
		
		if (this->refRule != nullptr) {
			this->initiated = true;
			break;
		}
		
		this->refRule = this->ruleMap.find(this->refKey)->second.get();
		this->initiated = this->refRule->initiate();
	} while (false);
	
	return this->initiated;
}

shared_ptr<RexerResult> Skip::rule(int id, const string & source, string::size_type start) {
	// TODO: check initiated
	
	RexerResult * refResult = this->refRule->execute(id, source, start);
	
	return make_shared<RexerResult>(refResult->success, refResult->start, refResult->end, refResult->most);
}
