// Compiler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "TextChecker.h"

const char txt[] =
{
	"\
	#define e 0\n\
	int fg = 2 + 2;\n\
	float gf = e;\n\
	int h = 134;\n\
	if(e = 0)\n\
	{\n\
		a++;\n\
	}\n\
	\n"
};

template<typename T>
struct Base
{
	void interface()
	{
		((T*)this)->bar();
	}
};

struct  Foo : Base<Foo>
{
	void bar()
	{
		cout << "Foo" << endl;
	}
};



int main()
{
	TextChecker tc;
	tc.checkText(txt);

	//system("pause");
	return 0;
}