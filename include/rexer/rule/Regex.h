#ifndef REXER_REGEX_H
#define REXER_REGEX_H

#include <regex>

#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Regex : public Rule {
		private:
			const regex reg;
			
		public:
			explicit Regex(int key, const map<int, shared_ptr<Rule>> & ruleMap, regex reg);
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) override;
	};
	
}

#endif //REXER_REGEX_H
