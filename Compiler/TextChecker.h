#pragma once
#include <iostream>
#include <string>
#include <list>

using namespace std;

#define syntaxSize 8

class TextChecker
{
public:
	TextChecker();
	~TextChecker();


	class Preprocessor
	{

	public:
		char *lookahead;
		size_t symbolsCount = 0;
		size_t counter = 0;
		string prefixNum = "";
		Preprocessor(char* smth)// 2 + 2 etc. //todo:change name
		{
			lookahead = (char*)malloc(sizeof(char) * getSize(smth));
			lookahead = smth;
			//cin >> lookahead;
			//cout << lookahead << endl;

		}

		size_t getSize(char* arr)
		{
			char* arr1 = arr;

			while (*arr1++);

			// << (int)(arr1 - arr - 1) << endl;
			return (int)(arr1 - arr - 1);
		}

		void toPrefix()
		{
			term();
			while (true)
			{
				if (lookahead[counter] == '+')
				{
					match('+');
					term();
					//cout << "+";
					symbolsCount++;
					prefixNum += "+";
				}
				else if (lookahead[counter] == '-')
				{
					match('-');
					term();
					//cout << "-";
					symbolsCount++;
					prefixNum += "-";
				}
				else if (lookahead[counter] == ' ')
				{
					counter++;
					//symbolsCount++;
				}
				else
				{
					//cout << endl;
					return;
				}
			}
		}

		int adder()
		{
			counter = 0;
			while (true)
			{
				if (prefixNum[counter] == '+')
				{
					//cout << (prefixNum[counter - 2] + prefixNum[counter - 1] - 48 * 2) << endl;
					return (prefixNum[counter - 2] + prefixNum[counter - 1] - 48 * 2);
				}
				else if (prefixNum[counter] == '-')
				{

					return (prefixNum[counter - 2] - prefixNum[counter - 1] - 48 * 2);
				}
				counter++;
				if (counter >= 100 || symbolsCount == counter)
				{
					cout << "GG" << endl;
					return -1;
				}

			}
		}


		void term()
		{

			while (lookahead[counter] == ' ')
			{
				match(' ');
			}

			if (isdigit(lookahead[counter]))
			{
				//cout << lookahead[counter];
				prefixNum += lookahead[counter];
				match(lookahead[counter]);
				symbolsCount++;

			}
			else
			{
				cout << endl << "error" << endl;
			}
		}

		void match(char s)
		{
			//counter++;
			if (lookahead[counter] == s)
			{
				counter++;
			}
			else
			{
				cout << endl << "error" << endl;
			}
		}
	};


	string syntax[syntaxSize];

	list<string> waitingVarsStr;
	list<int> waitingVarsInt;

	void checkText(const char* text)
	{
		string str = "";
		while (*text++)
		{
			if (*text == ' ')
				*text++;
			else if (*text == '\n')
				*text++;
			else if (*text == '\t')
				*text++;


			str += *text;

			for (size_t i = 0; i < syntaxSize; i++)
			{
				if (str == "int" || str == "float")
				{
					cout << str.c_str();
					onVar(text);
					str = "";
					break;
				}
				else if (str == "#define")
				{
					cout << str.c_str();
					onMacros(text);
					str = "";
					break;
				}
				else if (str == "if")
				{
					cout << str.c_str();
					onIf(text);
					str = "";
					break;
				}


			}
		}
		//cout << str.c_str() << endl;
	}

private:
	void onVar(const char *&text);
	void onMacros(const char *&text);
	void onIf(const char *&text);
	void checkDef(string &num);
};

