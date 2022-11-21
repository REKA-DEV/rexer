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
			vector<shared_ptr<Rule>> rules;
			map<int, shared_ptr<Rule>> ruleMap;
		
			template<typename _Tp, typename... _Args>
			Rule * nmake(_Args &&... _args) {
				shared_ptr<Rule> rule = make_shared<_Tp>(-1, this->ruleMap, forward<_Args>(_args)...);
				this->rules.push_back(rule);
				return rule.get();
			}
			
			template<typename _Tp, typename... _Args>
			Rule * make(int key, _Args &&... _args) {
				shared_ptr<Rule> rule = make_shared<_Tp>(key, this->ruleMap, forward<_Args>(_args)...);
				this->ruleMap[key] = rule;
				return rule.get();
			}
			
		public:
			
			template<typename... _Args>
			Rule * nmGroup(_Args &&... _args) {
				return this->nmake<Group>(forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * nmMultiple(_Args &&... _args) {
				return this->nmake<Multiple>(forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * nmOptional(_Args &&... _args) {
				return this->nmake<Optional>(forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * nmOr(_Args &&... _args) {
				return this->nmake<Or>(forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * nmRef(_Args &&... _args) {
				return this->nmake<Ref>(forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * nmRegex(_Args &&... _args) {
				return this->nmake<Regex>(forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * nmRun(_Args &&... _args) {
				return this->nmake<Run>(forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * nmSkip(_Args &&... _args) {
				return this->nmake<Skip>(forward<_Args>(_args)...);
			}
			
			template<typename... _Args>
			Rule * nmWord(_Args &&... _args) {
				return this->nmake<Word>(forward<_Args>(_args)...);
			}
			
			// ################################################################################################################################
			
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
