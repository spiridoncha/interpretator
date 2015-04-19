#include "Stack.h"

template <typename T>
void Stack<T>::resize()
{
	if (real_size == size)
	{
		T *p_new = new T[2*size];
		for(int i=0;i<real_size;++i)
		{
			p_new[i] = p[i];
		}
		size *= 2;
		delete[] p;
		p = p_new;
	}
}

template <typename T>
Stack<T>::Stack()
{
	size = 1;
	p = new T[size]; 
	real_size = 0;
}

template <typename T>
void Stack<T>::push(const T &elem)
{
	resize();
	p[real_size++] = elem;
}

template <typename T>
T Stack<T>::pop()
{
	if (is_Empty())
	{
		throw("Stack is Empty");
	}
	return p[--real_size];
}

template class Stack<int>;
template class Stack<type_of_lex>;
