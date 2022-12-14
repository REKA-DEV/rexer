#ifndef REXER_OR_H
#define REXER_OR_H

#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Or : public Rule {
		private:
			const map<int, shared_ptr<Rule>> & ruleMap;
			const vector<int> refKeys;
			
			vector<Rule *> refRules;
		
		public:
			explicit Or(int key, const map<int, shared_ptr<Rule>> & ruleMap, vector<int> refKeys);
			explicit Or(int key, const map<int, shared_ptr<Rule>> & ruleMap, vector<Rule *> refRules);
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) noexcept override;
	};
	
}

#endif //REXER_OR_H
