#include "String.h"
#include <iostream>
String::String(const String& other)
{
	size = other.size;
	str = new char[size+1];
	for(int i=0; i<=size; ++i)
	{
		str[i] = other.str[i];
	}
}

String::String(const char *other)
{
	size = strlen(other);
	str = new char[size+1];
	for(int i=0; i<=size; ++i)
	{
		str[i]=other[i];
	}
}

String& String::operator=(const String& other)
{
	size = other.size;
	delete[] str;
	//std::cout << size;
	str = new char[size+1];
	for(int i=0; i<=size; ++i)
	{
		str[i] = other.str[i];
	}
	return *this;
}

String& String::operator+=(const String &other)
{
	int tmp_size = size;
	size += other.size;
	char *p_new = new char[size+1];
	for(int i=0; i<tmp_size; ++i)
	{
		p_new[i] = str[i];
	}
	int j = 0;
	for(int i=tmp_size; i<=size; ++i)
	{
		p_new[i] = other.str[j++];
	}
	delete[] str;
	str = p_new;
	return *this;
}

String String::operator+(const String &other)
{
	//////////////////////
	return String();
}
