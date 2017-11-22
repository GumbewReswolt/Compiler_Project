#include <iostream>
#include "Compiler.h"
#include <fstream>
#include <string>

using namespace  std;

void main()
{
	fstream in("code.txt");
	string code = "";
	string codeline;
	while (getline(in, codeline))
	{
		code += codeline;
	}

	cout << code << endl;
	Compiler comp;
	comp.compile(code);
	cout << endl;
	cout << code << endl;
	system("pause");
}