#ifndef REXER_SKIP_H
#define REXER_SKIP_H

#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Skip : public Rule {
		private:
			const map<int, shared_ptr<Rule>> & ruleMap;
			const int refKey;
			
			Rule * refRule = nullptr;
		
		public:
			explicit Skip(int key, const map<int, shared_ptr<Rule>> & ruleMap, int refKey);
			explicit Skip(int key, const map<int, shared_ptr<Rule>> & ruleMap, Rule * refRule);
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) override;
	};
	
}

#endif //REXER_SKIP_H
