include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(rexer SHARED
        Rexer.cpp
        RexerResult.cpp
        Token.cpp

        rule/Rule.cpp
        rule/Group.cpp
        rule/Multiple.cpp
        rule/Optional.cpp
        rule/Or.cpp
        rule/Ref.cpp
        rule/Regex.cpp
        rule/Run.cpp
        rule/Skip.cpp
        rule/Word.cpp)
