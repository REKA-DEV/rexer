#include "rexer/rule/Group.h"

#include <iostream>

using namespace rexer;

Group::Group(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, vector<int> refKeys) : Rule(key), ruleMap(ruleMap), bundle(bundle), refKeys(move(refKeys)) {
	// EMPTY
}

Group::Group(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, vector<Rule *> refRules) : Rule(key), ruleMap(ruleMap), bundle(bundle), refRules(move(refRules)) {
	// EMPTY
}

bool Group::initiate() {
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

shared_ptr<RexerResult> Group::rule(int id, const string & source, string::size_type start) {
	// TODO: check initiated
	
	bool success = true;
	string::size_type end = start;
	vector<shared_ptr<Token>> tokens;
	RexerResult * most = nullptr;
	
	for (Rule * refRule: this->refRules) {
		RexerResult * refResult = refRule->execute(id, source, end);
		
		if (most == nullptr || (most->end < refResult->most->end)) {
			most = refResult->most;
		}
		
		cout << "group: " << refRule->getKey() << ", " << refResult->success << endl;
		
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
