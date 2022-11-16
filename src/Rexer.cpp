#include "rexer/Rexer.h"

using namespace rexer;

RexerResult * Rexer::execute(int key, const string & source) {
	if (!this->initiated) {
		for (auto & iterator : this->ruleMap) {
			iterator.second->initiate();
		}
		this->initiated = true;
	}
	
	this->id = this->id + 1;
	return this->ruleMap[key]->execute(this->id, source, 0);
}
