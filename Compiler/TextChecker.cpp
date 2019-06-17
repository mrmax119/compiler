#include "pch.h"
#include "TextChecker.h"


TextChecker::TextChecker()
{
	syntax[0] = "int";
	syntax[1] = "if";
	syntax[2] = "{";
	syntax[3] = "}";
	syntax[4] = "float";
	syntax[5] = "=";
	syntax[6] = "==";
	syntax[7] = ";";
}


TextChecker::~TextChecker()
{
}

void TextChecker::onVar(const char *&text)
{
	string name = "";
	*text++;
	*text++;
	while (*text == ' ')
	{
		*text++;
	}

	while (*text != '=')
	{
		if (*text == ' ')
		{
			*text++;
			break;
		}
		name += *text;
		*text++;
	}

	//cout << *text << endl;


	if (*text++ == '(')
	{
		//to do something
	}
	else
	{
		while (!isdigit(*text))
		{
			if (isalpha(*text))
				break;
			*text++;

		}

		string value = "";

		bool bl = false;
		while (*text != ';')
		{
			value += *text;

			if (*text == '+')
				bl = true;
			else if (*text == '-')
				bl = true;

			*text++;
		}


		if (bl)
		{
			Preprocessor p((char*)value.c_str());
			p.toPrefix();
			value = std::to_string(p.adder());
			//cout << value.c_str() << endl;
		}
		else if (!isdigit(atoi(value.c_str())))
		{
			list<string>::iterator itStr;
			list<int>::iterator itInt;

			for (itStr = waitingVarsStr.begin(), itInt = waitingVarsInt.begin(); itStr != waitingVarsStr.end(); itStr++, itInt++)
			{
				if (value == *itStr)
				{
					value = std::to_string(*itInt);
					break;
				}
			}
		}

		cout << " " << name.c_str() << " ";
		cout << "= " << value.c_str() << endl;
		*text++;

		//cout << *text << endl;
	}
	//todo:Variable table to keep all variables
}

// Macros = Define

void TextChecker::onMacros(const char *& text)
{
	string name = "";
	*text++;

	while (*text == ' ') *text++;

	while (*text != ' ')
	{
		name += *text;
		*text++;
	}

	while (*text == ' ') *text++;


	string value = "";

	while (*text != ' ')
	{
		if (*text == '\n')
			break;
		if (*text == '\t')
			break;

		value += *text;

		*text++;
	}

	waitingVarsStr.push_back(name);
	waitingVarsInt.push_back(atoi(value.c_str()));

	/**text++;
	*text++;*/

	cout << " " << name.c_str() << " " << value.c_str() << endl;
}

void setNum(string &str, const char *&text)
{
	while (*text != '=')
	{
		if (*text == ' ')
			break;
		if (*text == ')')
		{
			*text++;
			break;
		}

		str += *text;

		*text++;
	}
}

void TextChecker::checkDef(string &num)
{

	list<string>::iterator itStr;
	list<int>::iterator itInt;

	for (itStr = waitingVarsStr.begin(), itInt = waitingVarsInt.begin(); itStr != waitingVarsStr.end(); itStr++, itInt++)
	{
		if (num == *itStr)
		{
			num = std::to_string(*itInt);
			break;
		}
	}
}


void TextChecker::onIf(const char *& text)
{
	*text++;

	while (*text == ' ') *text++;

	cout << *text;

	*text++;

	while (*text == ' ') *text++;

	string firstNum = "";
	string secondNum = "";
	string sign = "";
	setNum(firstNum, text);

	while (*text == ' ') *text++;
	if (*text == '=')
	{
		*text++;
		sign = "=";
	}
	while (*text == ' ') *text++;

	setNum(secondNum, text);

	if (!isdigit(atoi(firstNum.c_str())))
	{
		checkDef(firstNum);
	}
	//else if (!isdigit(atoi(firstNum.c_str())))
	//{
	//	cout << "yo" << endl;//todo:checking through bool
	//}

	if (!isdigit(atoi(secondNum.c_str())))
	{
		checkDef(secondNum);
	}
	//else if (!isdigit(atoi(secondNum.c_str())))
	//{
	//	cout << "yo2" << endl;
	//}


	cout << firstNum << " == ";
	cout << secondNum << " is ";

	bool isTrue = false;

	if (sign == "=")
	{
		if (firstNum == secondNum)
		{
			cout << "true";
			isTrue = true;
		}
		else
		{
			cout << "false";
			isTrue = false;
		}

		cout << ")" << endl << "{" << endl;
	}

	char s;
	s = *text;
	while (s == ' ' || s == '\n' || s == '\t')
	{
		*text++;
		s = *text;
	}

	while (*text == '{') *text++;
	
	char s2;
	s2 = *text;
	while (s2 == ' ' || s2 == '\n' || s2 == '\t')
	{
		*text++;
		s2 = *text;
	}

	//*text++;

	string name2 = "";

	while (isalpha(*text))
	{
		name2 += *text;
		*text++;
	}

	//cout << *text << endl;

	s = *text;

	while (s == ' ')
	{
		*text++;
		s = *text;
	}

	string oper = "";

	while (s != ';')
	{
		oper += s;
		*text++;
		s = *text;
	}

	cout << name2 << endl << oper << endl;

	*text++;

	while (*text == ' ') *text++;

	s = *text;
	while (s == ' ' || s == '\n' || s == '\t')
	{
		*text++;
		s = *text;
	}

	while (*text == ' ') *text++;

	while (*text != '}') *text++;

	*text++;

	if (isTrue)
	{
		if (oper == "+")
		{
			//as ++
		}
	}
}

