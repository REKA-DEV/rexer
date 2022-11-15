#include "rexer/rule/Optional.h"

using namespace oportuna;

OptionalSyntax::OptionalSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int refKey) : OptionalSyntax(syntaxMap, -1, refKey) {
	// EMPTY
}

OptionalSyntax::OptionalSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, Syntax * refSyntax) : OptionalSyntax(syntaxMap, -1, refSyntax) {
	// EMPTY
}

OptionalSyntax::OptionalSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, int refKey) : Syntax(key), syntaxMap(syntaxMap), refKey(refKey) {
	// EMPTY
}

OptionalSyntax::OptionalSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, Syntax * refSyntax) : Syntax(key), syntaxMap(syntaxMap), refKey(-1), refSyntax(refSyntax) {
	// EMPTY
}

shared_ptr<ScanResult> OptionalSyntax::process(int scanIndex, const string & source, string::size_type start) {
	if (this->refSyntax == nullptr) {
		this->refSyntax = this->syntaxMap.find(this->refKey)->second.get();
	}
	
	shared_ptr<ScanResult> execute = this->refSyntax->execute(scanIndex, source, start);
	
	return make_shared<ScanResult>(true, execute->start, execute->success ? execute->end : execute->start, execute->tokens, execute->most);
}
