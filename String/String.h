#ifndef STRING_H
#define STRING_H
#include <string.h>
class String
{
	char *str;
	int size;
public:
	String() : str(nullptr) {}
	explicit String(const char* other);
	~String() { delete[] str; }
	String(const String&);
	String& operator=(const String&);
	String& operator+=(const String&);
	String operator+(const String&);
};
#endif
