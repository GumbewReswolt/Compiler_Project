#pragma once
#include "Compiler.h"
#include <string>
#include <list>

using namespace  std;

class Compiler
{
private:
	void removeSpaces(string&code);
	bool isLexeme(string::iterator it);
	list<string> tokenize(string&code);
public:
	string compile(string&code);
};

