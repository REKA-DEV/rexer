#ifndef REXER_REXERRESULT_H
#define REXER_REXERRESULT_H

#include "rexer/Token.h"

using namespace std;

namespace rexer {
	
	class RexerResult {
		public:
			const bool success;
			const string::size_type start;
			const string::size_type end;
			const vector<shared_ptr<Token>> tokens;
			RexerResult * most = nullptr;
			
			RexerResult(bool success, string::size_type start, string::size_type end);
			RexerResult(bool success, string::size_type start, string::size_type end, RexerResult * most);
			RexerResult(bool success, string::size_type start, string::size_type end, vector<shared_ptr<Token>> tokens);
			RexerResult(bool success, string::size_type start, string::size_type end, vector<shared_ptr<Token>> tokens, RexerResult * most);
			
			string toString();
	};
	
}

#endif //REXER_REXERRESULT_H
