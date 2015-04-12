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
public:
	Buffer(int s = 4) : real_size(0), size(s) { buf = new char[s]; }
	~Buffer() { delete[] buf; }
	void clear();
	void add(int ch);
	const char* operator()() { return buf; }
};
#endif
