#ifndef BUFFER_H
#define BUFFER_H
#include <string.h>
class Buffer
{
	char *buf;
	int real_size;
	int size;
	void re_size();
	Buffer(const Buffer&) {}
	void operator=(const Buffer&) {}
public:
	Buffer() : real_size(0), size(10) { buf = new char[10]; }
	~Buffer() { delete[] buf; }
	void clear();
	void add(int ch);
	const char* operator()() { return buf; }
};
#endif
