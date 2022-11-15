#ifndef REXER_REF_H
#define REXER_REF_H

#include <map>

#include "rexer/RexerResult.h"
#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Ref : public Rule {
		private:
			const map<int, shared_ptr<Rule>> & ruleMap;
			const int refKey;
			
			Rule * refRule = nullptr;
		
		public:
			explicit Ref(const map<int, shared_ptr<Rule>> & ruleMap, int key, int refKey);
			explicit Ref(const map<int, shared_ptr<Rule>> & ruleMap, int key, Rule * refRule);
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) override;
	};
	
}

#endif //REXER_REF_H
