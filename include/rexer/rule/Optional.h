#ifndef REXER_OPTIONAL_H
#define REXER_OPTIONAL_H

#include <map>
#include <memory>

#include "oportuna/scanner/ScanResult.h"
#include "oportuna/scanner/syntax/Syntax.h"

using namespace std;

namespace oportuna {
	
	class OptionalSyntax : public Syntax {
		private:
			const map<int, shared_ptr<Syntax>> & syntaxMap;
			const int refKey;
			
			Syntax * refSyntax = nullptr;
		
		public:
			OptionalSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int refKey);
			OptionalSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, Syntax * refSyntax);
			OptionalSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, int refKey);
			OptionalSyntax(const map<int, shared_ptr<Syntax>> & syntaxMap, int key, Syntax * refSyntax);
			
			shared_ptr<ScanResult> process(int scanIndex, const string & source, string::size_type start) override;
	};
	
}

#endif //OREXER_OPTIONAL_H
