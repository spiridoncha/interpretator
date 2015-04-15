#ifndef STRING_H
#define STRING_H
#include <string.h>
#include <iostream>
class String
{
	char *str;
	int size;
public:
	String() : str(nullptr), size(0) {}
	explicit String(const char* other);
	~String() { delete[] str; }
	String(const String&);
	static String int_to_str(const int n);
	String& operator=(const String&);
	String& operator+=(const String&);
	String operator+(const String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
};
#endif
