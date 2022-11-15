#ifndef REXER_REGEX_H
#define REXER_REGEX_H

#include <regex>

#include "rexer/RexerResult.h"
#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Regex : public Rule {
		private:
			const regex reg;
			
		public:
			explicit Regex(int key, regex reg);
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) override;
	};
	
}

#endif //REXER_REGEX_H
