#include "pch.h"
#include "MyString.h"


MyString::MyString()
{
	this->size = 0;
	this->data = nullptr;
	this->isMark = false;
}

MyString::MyString(char * str)
{
	this->size = getSize(str);
	this->data = str;
	this->isMark = false;
}


MyString::~MyString()
{
	if (isMark)
		free(this->data);
}

size_t __cdecl MyString::getSize(char * str)
{
	char* eos = str;

	while (*eos++);

	return (int)(eos - str - 1);
}

size_t __cdecl MyString::getSize(const char * str)
{
	const char* eos = str;

	while (*eos++);

	return (int)(eos - str - 1);
}

char * MyString::concat(char * str1, char * str2)
{
	size_t newSize = getSize(str1) + getSize(str2) + 1;

	char* newStr = (char*)malloc(sizeof(char) * newSize);
		
	size_t s = getSize(str1);

	for (size_t i = 0; i < s; i++)
	{

		newStr[i] = str1[i];
	}

	for (size_t i = s, j = 0; i < newSize - 1; i++, j++)
	{
		newStr[i] = str2[j];
	}
	
	newStr[newSize - 1] = '\0';

	//std::cout << newStr << std::endl;

	this->data = newStr;
	this->size = newSize;
	this->isMark = true;

	return newStr;
}

char * MyString::concat(const char * str1, const char * str2)
{
	size_t newSize = getSize(str1) + getSize(str2) + 1;

	char* newStr = (char*)malloc(sizeof(char) * newSize);

	size_t s = getSize(str1);

	for (size_t i = 0; i < s; i++)
	{

		newStr[i] = str1[i];
	}

	for (size_t i = s, j = 0; i < newSize - 1; i++, j++)
	{
		newStr[i] = str2[j];
	}

	newStr[newSize - 1] = '\0';

	//std::cout << newStr << std::endl;

	this->data = newStr;
	this->size = newSize;
	this->isMark = true;

	return newStr;
}


char* & MyString::operator=(const char *& str)
{
	size_t size = getSize(str);

	free(this->data);

	this->data = (char*)malloc(sizeof(char) * size);

	return data;
}
