#ifndef REXER_OPTIONAL_H
#define REXER_OPTIONAL_H

#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Optional : public Rule {
		private:
			const map<int, shared_ptr<Rule>> & ruleMap;
			const int refKey;
			
			Rule * refRule = nullptr;
		
		public:
			explicit Optional(int key, const map<int, shared_ptr<Rule>> & ruleMap, int refKey);
			explicit Optional(int key, const map<int, shared_ptr<Rule>> & ruleMap, Rule * refRule);
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) override;
	};
	
}

#endif //OREXER_OPTIONAL_H
