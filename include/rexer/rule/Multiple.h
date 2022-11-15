#ifndef REXER_MULTIPLE_H
#define REXER_MULTIPLE_H

#include <map>
#include <memory>

#include "oportuna/scanner/ScanResult.h"
#include "oportuna/scanner/syntax/Syntax.h"

using namespace std;

namespace oportuna {
	
	class MultipleSyntax : public Syntax {
		private:
			const map<int, shared_ptr<Syntax>> & syntaxMap;
			const bool bundle;
			const int refKey;
			
			Syntax * refSyntax = nullptr;
			
		public:
			MultipleSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, bool bundle, int refKey);
			MultipleSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, bool bundle, Syntax * refSyntax);
			MultipleSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, bool bundle, int refKey);
			MultipleSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, bool bundle, Syntax * refSyntax);
			
			shared_ptr<ScanResult> process(int scanIndex, const string & source, string::size_type start) override;
	};
	
}

#endif //REXER_MULTIPLE_H
