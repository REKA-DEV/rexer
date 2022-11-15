#ifndef REXER_OR_H
#define REXER_OR_H

#include <map>
#include <memory>
#include <vector>

#include "oportuna/scanner/ScanResult.h"
#include "oportuna/scanner/syntax/Syntax.h"

using namespace std;

namespace oportuna {
	
	class OrSyntax : public Syntax {
		private:
			const map<int, shared_ptr<Syntax>> & syntaxMap;
			const vector<int> refKeys;
			
			vector<Syntax *> refSyntaxes;
		
		public:
			OrSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, vector<int> refKeys);
			OrSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, vector<Syntax *> refSyntaxes);
			OrSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, vector<int> refKeys);
			OrSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, vector<Syntax *> refSyntaxes);
			
			shared_ptr<ScanResult> process(int scanIndex, const string & source, string::size_type start) override;
	};
	
}

#endif //REXER_OR_H
