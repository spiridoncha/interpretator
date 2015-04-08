#include "String.h"
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
	str = new char[size+1];
	for(int i=0; i<=size; ++i)
	{
		str[i] = other.str[i];
	}
	return *this;
}

String String::operator+(const String& other)
{
	//////////////////////
	return String();
}
