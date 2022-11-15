#include "rexer/rule/Run.h"

using namespace rexer;

Run::Run(int key, runnable run) : Rule(key), run(move(run)) {
	// EMPTY
}

bool Run::initiate() {
	this->initiated = true;
	return this->initiated;
}

shared_ptr<RexerResult> Run::rule(int id, const string & source, string::size_type start) {
	return this->run(id, source, start);
}
