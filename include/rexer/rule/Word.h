#ifndef REXER_WORD_H
#define REXER_WORD_H

#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Word : public Rule {
		private:
			const string word;
			const string::size_type length;
		
		public:
			explicit Word(int key, const map<int, shared_ptr<Rule>> & ruleMap, string word);
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) noexcept override;
	};
	
}

#endif //REXER_WORD_H
