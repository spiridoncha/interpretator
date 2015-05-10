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
	Buffer() : real_size(0) { buf = new char[(size=4)+1]; }
	Buffer(const char **table1, const char **table2) : real_size(0)
	{
		int i = 0;
		int max_len1 = 0, max_len2 = 0;
		while(table1[i])
		{
			int len = strlen(table1[i++]);
			max_len1 = len > max_len1 ? len : max_len1;
		}
		i = 0;
		while(table2[i])
		{
			int len = strlen(table2[i++]);
			max_len2 = len > max_len2 ? len : max_len2;
		}
		size = max_len1 > max_len2 ? max_len1 : max_len2;
		buf = new char[size+1];
	}
	~Buffer() { delete[] buf; }
	void clear();
	void add(int ch);
	const char* operator()() { return buf; }
};
#endif
