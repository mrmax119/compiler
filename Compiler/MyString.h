#pragma once
#include <iostream>

class MyString
{
public:
	MyString();
	MyString(char* str);
	~MyString();

	size_t size;

	size_t __cdecl getSize(char* str);
	size_t __cdecl getSize(const char* str);

	char* concat(char* str1, char* str2);
	char* concat(const char* str1, const char* str2);

	char*& operator=(const char*& str);
	friend std::ostream& operator<<(std::ostream& out, const MyString &str)
	{
		out << str.data;

		return out;
	}

public:
	char* data;
	bool isMark; // for free()
};

