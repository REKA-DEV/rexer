#include "rexer/Rexer.h"

//#include "oportuna/scanner/syntax/GroupSyntax.h"
//#include "oportuna/scanner/syntax/MultipleSyntax.h"
//#include "oportuna/scanner/syntax/OptionalSyntax.h"
//#include "oportuna/scanner/syntax/OrSyntax.h"
//#include "oportuna/scanner/syntax/RefSyntax.h"
//#include "oportuna/scanner/syntax/RegexSyntax.h"
//#include "oportuna/scanner/syntax/RunSyntax.h"
//#include "oportuna/scanner/syntax/SkipSyntax.h"
//#include "oportuna/scanner/syntax/WordSyntax.h"

using namespace rexer;

Syntax * Scanner::sGroup(bool bundle, vector<int> refKeys) {
	shared_ptr<Syntax> syntax = make_shared<GroupSyntax>(this->syntaxTable.getMap(), bundle, move(refKeys));
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sGroup(bool bundle, vector<Syntax *> refSyntaxes) {
	shared_ptr<Syntax> syntax = make_shared<GroupSyntax>(this->syntaxTable.getMap(), bundle, move(refSyntaxes));
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sGroup(int key, bool bundle, vector<int> refKeys) {
	shared_ptr<Syntax> syntax = make_shared<GroupSyntax>(this->syntaxTable.getMap(), key, bundle, move(refKeys));
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

Syntax * Scanner::sGroup(int key, bool bundle, vector<Syntax *> refSyntaxes) {
	shared_ptr<Syntax> syntax = make_shared<GroupSyntax>(this->syntaxTable.getMap(), key, bundle, move(refSyntaxes));
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

// ################################################################################################################################

Syntax * Scanner::sMultiple(bool bundle, int refKey) {
	shared_ptr<Syntax> syntax = make_shared<MultipleSyntax>(this->syntaxTable.getMap(), bundle, refKey);
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sMultiple(bool bundle, Syntax * refSyntax) {
	shared_ptr<Syntax> syntax = make_shared<MultipleSyntax>(this->syntaxTable.getMap(), bundle, refSyntax);
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sMultiple(int key, bool bundle, int refKey) {
	shared_ptr<Syntax> syntax = make_shared<MultipleSyntax>(this->syntaxTable.getMap(), key, bundle, refKey);
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

Syntax * Scanner::sMultiple(int key, bool bundle, Syntax * refSyntax) {
	shared_ptr<Syntax> syntax = make_shared<MultipleSyntax>(this->syntaxTable.getMap(), key, bundle, refSyntax);
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

// ################################################################################################################################

Syntax * Scanner::sOptional(int refKey) {
	shared_ptr<Syntax> syntax = make_shared<OptionalSyntax>(this->syntaxTable.getMap(), refKey);
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sOptional(Syntax * refSyntax) {
	shared_ptr<Syntax> syntax = make_shared<OptionalSyntax>(this->syntaxTable.getMap(), refSyntax);
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sOptional(int key, int refKey) {
	shared_ptr<Syntax> syntax = make_shared<OptionalSyntax>(this->syntaxTable.getMap(), key, refKey);
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

Syntax * Scanner::sOptional(int key, Syntax * refSyntax) {
	shared_ptr<Syntax> syntax = make_shared<OptionalSyntax>(this->syntaxTable.getMap(), key, refSyntax);
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

// ################################################################################################################################

Syntax * Scanner::sOr(vector<int> refKeys) {
	shared_ptr<Syntax> syntax = make_shared<OrSyntax>(this->syntaxTable.getMap(), move(refKeys));
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sOr(vector<Syntax *> refSyntaxes) {
	shared_ptr<Syntax> syntax = make_shared<OrSyntax>(this->syntaxTable.getMap(), move(refSyntaxes));
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sOr(int key, vector<int> refKeys) {
	shared_ptr<Syntax> syntax = make_shared<OrSyntax>(this->syntaxTable.getMap(), key, move(refKeys));
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

Syntax * Scanner::sOr(int key, vector<Syntax *> refSyntaxes) {
	shared_ptr<Syntax> syntax = make_shared<OrSyntax>(this->syntaxTable.getMap(), key, move(refSyntaxes));
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

// ################################################################################################################################

Syntax * Scanner::sRef(int refKey) {
	shared_ptr<Syntax> syntax = make_shared<RefSyntax>(this->syntaxTable.getMap(), refKey);
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sRef(Syntax * refSyntax) {
	shared_ptr<Syntax> syntax = make_shared<RefSyntax>(this->syntaxTable.getMap(), refSyntax);
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sRef(int key, int refKey) {
	shared_ptr<Syntax> syntax = make_shared<RefSyntax>(this->syntaxTable.getMap(), key, refKey);
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

Syntax * Scanner::sRef(int key, Syntax * refSyntax) {
	shared_ptr<Syntax> syntax = make_shared<RefSyntax>(this->syntaxTable.getMap(), key, refSyntax);
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

// ################################################################################################################################

Syntax * Scanner::sRegex(regex reg) {
	shared_ptr<Syntax> syntax = make_shared<RegexSyntax>(move(reg));
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sRegex(int key, regex reg) {
	shared_ptr<Syntax> syntax = make_shared<RegexSyntax>(key, move(reg));
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

// ################################################################################################################################

Syntax * Scanner::sRun(runnable run) {
	shared_ptr<Syntax> syntax = make_shared<RunSyntax>(move(run));
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sRun(int key, runnable run) {
	shared_ptr<Syntax> syntax = make_shared<RunSyntax>(key, move(run));
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

// ################################################################################################################################

Syntax * Scanner::sSkip(int refKey) {
	shared_ptr<Syntax> syntax = make_shared<SkipSyntax>(this->syntaxTable.getMap(), refKey);
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sSkip(Syntax * refSyntax) {
	shared_ptr<Syntax> syntax = make_shared<SkipSyntax>(this->syntaxTable.getMap(), refSyntax);
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sSkip(int key, int refKey) {
	shared_ptr<Syntax> syntax = make_shared<SkipSyntax>(this->syntaxTable.getMap(), key, refKey);
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

Syntax * Scanner::sSkip(int key, Syntax * refSyntax) {
	shared_ptr<Syntax> syntax = make_shared<SkipSyntax>(this->syntaxTable.getMap(), key, refSyntax);
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

// ################################################################################################################################

Syntax * Scanner::sWord(string word) {
	shared_ptr<Syntax> syntax = make_shared<WordSyntax>(move(word));
	this->syntaxTable.addToList(syntax);
	
	return syntax.get();
}

Syntax * Scanner::sWord(int key, string word) {
	shared_ptr<Syntax> syntax = make_shared<WordSyntax>(key, move(word));
	this->syntaxTable.add(key, syntax);
	
	return syntax.get();
}

// ################################################################################################################################

RexerResult * Rexer::execute(int key, const string & source) {
	if (!this->initiated) {
		for (auto & iterator : this->ruleMap) {
			iterator.second->initiate();
		}
	}
	
	this->id = this->id + 1;
	return this->ruleMap[key]->execute(this->id, source, 0);
}
