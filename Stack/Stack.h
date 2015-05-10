#ifndef STACK_H
#define STACK_H
#include "../Scanner/Lex/Lex.h"
#include "../String/String.h"
template <typename T>
class Stack
{
	//friend class Stack_Iterator;
public:
	Stack();
	~Stack() { delete[] p; }
	void out();
	void reset() { real_size = 0;}
	void push(const T&);
	T pop();
	bool is_Empty() const { return real_size == 0;}
	Stack(const Stack&);
	void operator=(const Stack&);
private:
	void resize();
	T* p;
	int size;
	int real_size;
};
#endif
