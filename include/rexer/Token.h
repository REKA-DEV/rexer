#ifndef REXER_TOKEN_H
#define REXER_TOKEN_H

#include <memory>
#include <vector>

using namespace std;

namespace rexer {
	
	class Token {
		public:
			const int key;
			const string::size_type start;
			const string::size_type end;
			const string value;
			const vector<shared_ptr<Token>> children;
			
			Token(int key, string::size_type start, string::size_type end, string value);
			Token(int key, string::size_type start, string::size_type end, vector<shared_ptr<Token>> children);
			
			string toString();
			string toString(int depth);
	};
	
}

#endif //REXER_TOKEN_H
