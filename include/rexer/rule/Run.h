#ifndef REXER_RUN_H
#define REXER_RUN_H

#include "rexer/RexerResult.h"
#include "rexer/rule/Rule.h"

using namespace std;

namespace rexer {
	
	class Run : public Rule {
		private:
			const runnable run;
		
		public:
			explicit Run(int key, runnable run);
			
			bool initiate() override;
			shared_ptr<RexerResult> rule(int id, const string & source, string::size_type start) override;
	};
	
}

#endif //REXER_RUN_H
