#ifndef REXER_REF_H
#define REXER_REF_H

#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Ref : public Rule {
		private:
			const map<int, shared_ptr<Rule>> & ruleMap;
			const int refKey;
			
			Rule * refRule = nullptr;
		
		public:
			explicit Ref(int key, const map<int, shared_ptr<Rule>> & ruleMap, int refKey);
			explicit Ref(int key, const map<int, shared_ptr<Rule>> & ruleMap, Rule * refRule);
			
			RexerResult * execute(int id, const string & source, string::size_type start) noexcept override;
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) noexcept override;
	};
	
}

#endif //REXER_REF_H
