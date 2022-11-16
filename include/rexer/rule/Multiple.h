#ifndef REXER_MULTIPLE_H
#define REXER_MULTIPLE_H

#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Multiple : public Rule {
		private:
			const map<int, shared_ptr<Rule>> & ruleMap;
			const bool bundle;
			const int refKey;
			
			Rule * refRule = nullptr;
		
		public:
			explicit Multiple(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, int refKey);
			explicit Multiple(int key, const map<int, shared_ptr<Rule>> & ruleMap, bool bundle, Rule * refRule);
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) override;
	};
	
}

#endif //REXER_MULTIPLE_H
