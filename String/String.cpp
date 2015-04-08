#include "String.h"
String::String(const String& other)
{
	size = other.size;
	str = new char[size+1];
	strcpy(str, other.str);
}

String::String(const char *other)
{
	size = strlen(other);
	str = new char[size+1];
	strcpy(str, other);
}

String String::int_to_str(const int n)
{
	int i = n;
	int mod;
	String tmp("");
	while (i)
	{
		mod = i%10;
		mod += '0';
		char *p = new char[2];
		p[0] = mod;
		p[1] = '\0';
		tmp += String(p);
		delete[] p;
		i/=10;
	}
	return tmp;
}

String& String::operator=(const String& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] str;
	size = other.size;
	str = new char[size+1];
	strcpy(str, other.str);
	return *this;
}

String& String::operator+=(const String &other)
{
	size += other.size;
	char *p_new = new char[size+1];
	strcpy(p_new, str);
	strcat(p_new, other.str);
	delete[] str;
	str  = p_new;
	return *this;
}

std::ostream& operator<<(std::ostream &out, const String &st)
{
	out << st.str;
	return out;
}

String String::operator+(const String &other)
{
	//////////////////////
	return String();
}
