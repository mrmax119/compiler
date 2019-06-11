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

	waitingVarsStr[0] = "e";
	waitingVarsInt[0] = 100;
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
			for (size_t i = 0; i < 1; i++)
			{
				if (value == waitingVarsStr[i])
				{
					value = std::to_string(waitingVarsInt[i]);
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
	for (size_t i = 0; i < 1; i++)
	{
		if (num == waitingVarsStr[i])
		{
			num = std::to_string(waitingVarsInt[i]);
			break;
		}
	}
}


void TextChecker::onIf(const char *& text)
{
	*text++;

	while (*text == ' ') *text++;

	cout << *text << endl;

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


	cout << firstNum << endl;
	cout << secondNum << endl;

	if (sign == "=")
	{
		if (atoi(firstNum.c_str()) == atoi(secondNum.c_str()))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}

}

