#include "Compiler.h"
#include  <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

void Compiler::removeSpaces(string&code)
{
	auto it = remove_if(code.begin(), code.end(), ::isspace);
	code.erase(it, code.end());
}
bool Compiler::isLexeme(string::iterator it)
{
	string lexemes = ">;=*/+-(){}[]";
	for (int i = 0; i < lexemes.size(); i++)
	{
		if (*it == lexemes[i])
		{
			return true;
		}
	}
	return false;
}
list<string> Compiler::tokenize(string&code)
{
	auto itrLeft = code.begin();
	list<string>tokens;
	for (auto itrRight = code.begin(); itrRight != code.end(); ++itrRight)
	{
		if (isLexeme(itrRight))
		{
			if (itrRight!=itrLeft)
			{
				tokens.push_back(string(itrLeft, itrRight));
			}
			itrLeft = itrRight;
			tokens.push_back(string(itrRight, ++itrLeft));
		}
	}
	for (auto it=tokens.begin(); it!=tokens.end(); ++it)
	{
		cout << *it << endl;
	}
	return tokens;
}

string Compiler::compile(string&code)
{
	removeSpaces(code);
	tokenize(code);
	return string();
}
