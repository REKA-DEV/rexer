#ifndef REXER_GROUP_H
#define REXER_GROUP_H

#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Group : public Rule {
		private:
			const map<int, shared_ptr<Rule>> & ruleMap;
			const bool bundle;
			const vector<int> refKeys;
			
			vector<Rule *> refRules;
		
		public:
			explicit Group(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, vector<int> refKeys);
			explicit Group(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, vector<Rule *> refRules);
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) override;
	};
	
}

#endif //REXER_GROUP_H
