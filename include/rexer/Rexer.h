#ifndef REXER_REXER_H
#define REXER_REXER_H

#include "rexer/RexerResult.h"
#include "rexer/rule/Rule.h"
#include "rexer/rule/Group.h"
#include "rexer/rule/Multiple.h"
#include "rexer/rule/Optional.h"
#include "rexer/rule/Or.h"
#include "rexer/rule/Ref.h"
#include "rexer/rule/Regex.h"
#include "rexer/rule/Run.h"
#include "rexer/rule/Skip.h"
#include "rexer/rule/Word.h"

using namespace std;

namespace rexer {
	
	class Rexer {
		private:
			bool initiated = false;
			int id = 0;
			map<int, shared_ptr<Rule>> ruleMap;
		
		public:
			
			template<typename _Tp, typename... _Args>
			Rule * make(int key, _Args &&... _args) {
				shared_ptr<Rule> rule = make_shared<_Tp>(key, this->ruleMap, forward<_Args>(_args)...);
				this->ruleMap[key] = rule;
				return rule.get();
			}
			
			template<typename... _Args>
			Rule * mGroup(int key, _Args &&... _args) {
				return this->make<Group>(key, forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * mMultiple(int key, _Args &&... _args) {
				return this->make<Multiple>(key, forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * mOptional(int key, _Args &&... _args) {
				return this->make<Optional>(key, forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * mOr(int key, _Args &&... _args) {
				return this->make<Or>(key, forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * mRef(int key, _Args &&... _args) {
				return this->make<Ref>(key, forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * mRegex(int key, _Args &&... _args) {
				return this->make<Regex>(key, forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * mRun(int key, _Args &&... _args) {
				return this->make<Run>(key, forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * mSkip(int key, _Args &&... _args) {
				return this->make<Skip>(key, forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * mWord(int key, _Args &&... _args) {
				return this->make<Word>(key, forward<_Args>(_args)...);
			}
			
			RexerResult * execute(int key, const string & source);
	};
	
}

#endif //REXER_REXER_H
