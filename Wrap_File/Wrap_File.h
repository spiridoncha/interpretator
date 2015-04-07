#ifndef WRAP_FILE_H
#define WRAP_FILE_H
#include <stdio.h>
#pragma once
class Ref
{
	unsigned int count;
public:
	Ref() : count(0) {}
	void AddRef() { ++count; }
	unsigned int DelRef() { return --count; }
};

class Wrap_File
{
	FILE *file;
	Ref *ref;
public:
	Wrap_File(const char *nameOfFile) : file(fopen(nameOfFile, "r")) 
	{ 
		if (file == NULL) { throw("lal"); } //class of except ...............................
		ref = new Ref(); ref->AddRef();
	}
	Wrap_File(const Wrap_File &other);
	Wrap_File& operator=(const Wrap_File &other);
	Wrap_File& operator=(Wrap_File &&other);
	Wrap_File(Wrap_File &&other) { file = other.file; ref = other.ref; other.file = nullptr; other.ref = nullptr; }
	~Wrap_File()
	{ 
		if ((ref != nullptr) && (ref->DelRef() == 0)) 
		{ 
			delete ref; fclose(file);
		} 
		if ((!ref) && (file)) { fclose(file); }
	}
	int get_Char() 
	{
		return getc(file);
	}
};

#endif
