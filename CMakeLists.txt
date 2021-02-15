cmake_minimum_required(VERSION 3.10.2)
project(Project_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project_1 main.cpp Lexer.cpp Lexer.h MatcherAutomaton.cpp MatcherAutomaton.h Automaton.cpp Automaton.h Token.cpp Token.h StringAutomaton.cpp StringAutomaton.h IDAutomata.cpp IDAutomata.h CommentAutomaton.cpp CommentAutomaton.h Parser.cpp Parser.h DatalogProgram.cpp DatalogProgram.h Rule.cpp Rule.h Predicate.cpp Predicate.h Parameter.cpp Parameter.h ExpressionParam.cpp ExpressionParam.h PlainParam.cpp PlainParam.h)