// Compiler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "TextChecker.h"
#include "MyString.h"

const char txt[] =
{
	"\
	#define b 10\n\
	int fg = 2 + 2;\n\
	float gf = b;\n\
	int h = 134;\n\
	if(b = 10)\n\
	{\n\
		h+;\n\
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

	//MyString ms = (char*)"sad";
	//const char* s = "str";
	//const char* ss = (char*)"ret";
	//ms.concat(s, ss);
	//cout << ms.data << endl;

	//ms = (char*)"gt";

	//cout << ms.data << endl;
	//cout << ms << endl;

	//free(ms.data);
		
	system("pause");
	return 0;
}