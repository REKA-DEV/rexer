#include "rexer/rule/Multiple.h"

using namespace oportuna;

MultipleSyntax::MultipleSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, bool bundle, int refKey) : MultipleSyntax(syntaxMap, -1, bundle, refKey) {
	// EMPTY
}

MultipleSyntax::MultipleSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, bool bundle, Syntax * refSyntax) : MultipleSyntax(syntaxMap, -1, bundle, refSyntax) {
	// EMPTY
}

MultipleSyntax::MultipleSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, bool bundle, int refKey) : Syntax(key), syntaxMap(syntaxMap), bundle(bundle), refKey(refKey) {
	// EMPTY
}

MultipleSyntax::MultipleSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, bool bundle, Syntax * refSyntax) : Syntax(key), syntaxMap(syntaxMap), bundle(bundle), refKey(-1), refSyntax(refSyntax) {
	// EMPTY
}

shared_ptr<ScanResult> MultipleSyntax::process(int scanIndex, const string & source, string::size_type start) {
	if (this->refSyntax == nullptr) {
		this->refSyntax = this->syntaxMap.find(this->refKey)->second.get();
	}
	
	string::size_type end = start;
	vector<shared_ptr<Token>> tokens;
	ScanResult * most = nullptr;
	
	while (end < source.length()) {
		shared_ptr<ScanResult> execute = this->refSyntax->execute(scanIndex, source, end);
		
		if (most == nullptr || (most->end < execute->most->end)) {
			most = execute->most;
		}
		
		if (!execute->success) {
			break;
		}
		
		end = execute->end;
		copy(execute->tokens.begin(), execute->tokens.end(), back_inserter(tokens));
	}
	
	shared_ptr<ScanResult> scanResult;
	
	if (this->bundle) {
		scanResult = make_shared<ScanResult>(true, start, end, vector<shared_ptr<Token>>({
			make_shared<Token>(this->key, start, end, tokens)
		}), most);
	} else {
		scanResult = make_shared<ScanResult>(true, start, end, tokens, most);
	}
	
	return scanResult;
}
