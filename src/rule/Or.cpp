#include "rexer/rule/Or.h"

using namespace oportuna;

OrSyntax::OrSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, vector<int> refKeys) : OrSyntax(syntaxMap, -1, move(refKeys)) {
	// EMPTY
}

OrSyntax::OrSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, vector<Syntax *> refSyntaxes) : OrSyntax(syntaxMap, -1, move(refSyntaxes)) {
	// EMPTY
}

OrSyntax::OrSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, vector<int> refKeys) : Syntax(key), syntaxMap(syntaxMap), refKeys(move(refKeys)) {
	// EMPTY
}

OrSyntax::OrSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, vector<Syntax *> refSyntaxes) : Syntax(key), syntaxMap(syntaxMap), refSyntaxes(move(refSyntaxes)) {
	// EMPTY
}

shared_ptr<ScanResult> OrSyntax::process(int scanIndex, const string & source, string::size_type start) {
	if (this->refSyntaxes.empty()) {
		for (auto iterator = this->refKeys.begin(); iterator < this->refKeys.end(); iterator++) {
			this->refSyntaxes.push_back(this->syntaxMap.find(*iterator)->second.get());
		}
	}
	
	shared_ptr<ScanResult> result;
	ScanResult * most = nullptr;
	
	for (Syntax * refSyntax: this->refSyntaxes) {
		shared_ptr<ScanResult> execute = refSyntax->execute(scanIndex, source, start);
		
		if (result == nullptr || (execute->success && (result->end < execute->end))) {
			result = execute;
		}
		
		if (most == nullptr || (most->end < execute->most->end)) {
			most = execute->most;
		}
	}
	
	return make_shared<ScanResult>(result->success, result->start, result->end, result->tokens, most);
}
