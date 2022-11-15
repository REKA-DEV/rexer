#ifndef REXER_REXER_H
#define REXER_REXER_H

#include <map>
#include <memory>
#include <regex>
#include <vector>

#include "rexer/RexerResult.h"
#include "rexer/rule/Rule.h"

//#include "oportuna/scanner/syntax/Syntax.h"
//#include "oportuna/scanner/syntax/RunSyntax.h"
//#include "oportuna/util/Table.h"

using namespace std;

namespace rexer {
	
	class Rexer {
		private:
			bool initiated = false;
			int id = 0;
			map<int, shared_ptr<Rule>> ruleMap;
		
		public:
			
//			Syntax * sGroup(bool bundle, vector<int> refKeys);
//			Syntax * sGroup(bool bundle, vector<Syntax *> refSyntaxes);
//			Syntax * sGroup(int key, bool bundle, vector<int> refKeys);
//			Syntax * sGroup(int key, bool bundle, vector<Syntax *> refSyntaxes);
//
//			Syntax * sMultiple(bool bundle, int refKey);
//			Syntax * sMultiple(bool bundle, Syntax * refSyntax);
//			Syntax * sMultiple(int key, bool bundle, int refKey);
//			Syntax * sMultiple(int key, bool bundle, Syntax * refSyntax);
//
//			Syntax * sOptional(int refKey);
//			Syntax * sOptional(Syntax * refSyntax);
//			Syntax * sOptional(int key, int refKey);
//			Syntax * sOptional(int key, Syntax * refSyntax);
//
//			Syntax * sOr(vector<int> refKeys);
//			Syntax * sOr(vector<Syntax *> refSyntaxes);
//			Syntax * sOr(int key, vector<int> refKeys);
//			Syntax * sOr(int key, vector<Syntax *> refSyntaxes);
//
//			Syntax * sRef(int refKey);
//			Syntax * sRef(Syntax * refSyntax);
//			Syntax * sRef(int key, int refKey);
//			Syntax * sRef(int key, Syntax * refSyntax);
//
//			Syntax * sRegex(regex reg);
//			Syntax * sRegex(int key, regex reg);
//
//			Syntax * sRun(runnable run);
//			Syntax * sRun(int key, runnable run);
//
//			Syntax * sSkip(int refKey);
//			Syntax * sSkip(Syntax * refSyntax);
//			Syntax * sSkip(int key, int refKey);
//			Syntax * sSkip(int key, Syntax * refSyntax);
//
//			Syntax * sWord(string word);
//			Syntax * sWord(int key, string word);
			
			RexerResult * execute(int key, const string & source);
	};
	
}

#endif //REXER_REXER_H
