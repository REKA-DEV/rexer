#include "rexer/rule/Ref.h"

using namespace rexer;

Ref::Ref(int key, const map<int, shared_ptr<Rule>> & ruleMap, int refKey) : Rule(key), ruleMap(ruleMap), refKey(refKey) {
	// EMPTY
}

Ref::Ref(int key, const map<int, shared_ptr<Rule>> & ruleMap, Rule * refRule) : Rule(key), ruleMap(ruleMap), refKey(-1), refRule(refRule) {
	// EMPTY
}

bool Ref::initiate() {
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

RexerResult * Ref::execute(int id, const string & source, string::size_type start) {
	// TODO: check initiated
	
	return this->refRule->execute(id, source, start);
}

shared_ptr<RexerResult> Ref::rule(int id, const string & source, string::size_type start) {
	// TODO: check initiated
	
	return this->refRule->rule(id, source, start);
}
