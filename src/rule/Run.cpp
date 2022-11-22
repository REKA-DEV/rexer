#include "rexer/rule/Run.h"

using namespace rexer;

Run::Run(int key, const map<int, shared_ptr<Rule>> & ruleMap, runnable run) : Rule(key), run(move(run)) {
	// EMPTY
}

bool Run::initiate() {
	this->initiated = true;
	return this->initiated;
}

shared_ptr<RexerResult> Run::rule(int id, const string & source, string::size_type start) noexcept {
	return this->run(id, source, start);
}
