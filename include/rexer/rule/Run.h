#ifndef REXER_RUN_H
#define REXER_RUN_H

#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Run : public Rule {
		private:
			const runnable run;
		
		public:
			explicit Run(int key, const map<int, shared_ptr<Rule>> & ruleMap, runnable run);
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) noexcept override;
	};
	
}

#endif //REXER_RUN_H
