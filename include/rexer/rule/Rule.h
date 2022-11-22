#ifndef REXER_RULE_H
#define REXER_RULE_H

#include <functional>
#include <map>

#include "rexer/RexerResult.h"

using namespace std;

namespace rexer {
	
	typedef function<shared_ptr<RexerResult>(int, const string &, string::size_type)> runnable;
	
	class Rule {
		protected:
			bool initiated = false;
			const int key;
			map<pair<int, string::size_type>, shared_ptr<RexerResult>> rexerResultMap;
		
		public:
			explicit Rule(int key);
			
			int getKey();
			
			virtual RexerResult * execute(int id, const string & source, string::size_type start) noexcept;
			
			virtual bool initiate() = 0;
			virtual shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) noexcept = 0;
			
			virtual ~Rule() = default;
	};
	
}

#endif //REXER_RULE_H
