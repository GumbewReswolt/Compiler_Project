#include  <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <list>
using namespace std;
class Compiler
{
private:
	void removeSpaces(string&code)
	{
		auto it = remove_if(code.begin(), code.end(), ::isspace);
		code.erase(it, code.end());
	}
	bool isLexem(string::iterator it)
	{
		string lexems = ">;=*/+-(){}[]";
		for (int i = 0; i<lexems.size(); i++)
		{
			if (*it == lexems[i])
			{
				return true;
			}
		}
		return false;
	}
	list<string> tokenize (string&code)
	{
		auto itrLeft = code.begin();
		list<string>tokens;
		for (auto itrRight=code.begin(); itrRight!=code.end();itrRight++)
		{
			if (isLexem(itrRight))
			{
				tokens.push_back(string(itrLeft,itrRight));
				itrLeft = itrRight;
				tokens.push_back(string(itrRight,++itrLeft));
			}
		}
		for (auto it=tokens.begin();it!=tokens.end();it++)
		{
			cout << *it << endl;
		}
		return tokens;
	}
	void seperateComAndArg(list<string>&tokens)
	{
		string token;
		while (!tokens.empty())
		{
			auto it =tokens.begin();
			token = *it;
			tokens.pop_front();

		}
	}
public:
	string compile(string&code)
	{
		removeSpaces(code);
		tokenize(code);
		return string();
	}
};

void main ()
{
	fstream in("code.txt");
	string code="";
	string codeline;
	while (getline(in, codeline))
	{
		code += codeline;
	}
	
	cout << code<<endl;
	Compiler comp;
	comp.compile(code);
	cout << endl;
	cout << code << endl;
	system("pause");
}