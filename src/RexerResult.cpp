#include "oportuna/scanner/ScanResult.h"

#include <sstream>

using namespace oportuna;

ScanResult::ScanResult(bool success, string::size_type start, string::size_type end) : success(success), start(start), end(end) {
	// EMPTY
}

ScanResult::ScanResult(bool success, string::size_type start, string::size_type end, ScanResult * most) : success(success), start(start), end(end), most(most) {
	// EMPTY
}

ScanResult::ScanResult(bool success, string::size_type start, string::size_type end, vector<shared_ptr<Token>> tokens) : success(success), start(start), end(end), tokens(move(tokens)) {
	// EMPTY
}

ScanResult::ScanResult(bool success, string::size_type start, string::size_type end, vector<shared_ptr<Token>> tokens, ScanResult * most) : success(success), start(start), end(end), tokens(move(tokens)), most(most) {
	// EMPTY
}

string ScanResult::toString() {
	ostringstream stream;
	
	stream << "success: " << this->success << endl;
	stream << "start: " << this->start << endl;
	stream << "end: " << this->end << endl;
	stream << endl;
	
	for (const shared_ptr<Token> & token: this->tokens) {
		stream << token->toString() << endl;
	}
	
	return stream.str();
}
