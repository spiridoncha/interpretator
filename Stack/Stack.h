#ifndef STACK_H
#define STACK_H
#include "../Scanner/Lex/Lex.h"
template <typename T>
class Stack
{
	//friend class Stack_Iterator;
public:
	explicit Stack();
	~Stack() { delete[] p; }
	void push(const T&);
	T pop();
	bool is_Empty() const { return real_size == 0;}
private:
	Stack(const Stack&) {}
	void operator=(const Stack&) {}
	void resize();
	T* p;
	int size;
	int real_size;
};
#endif
