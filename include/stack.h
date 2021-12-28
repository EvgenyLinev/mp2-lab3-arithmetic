// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память

#ifndef __STACK_H__

#define __STACK_H__

#include <vector>
#include <iostream>
using namespace std;

template <class T>
class TStack
{
private:
	T* stack;
	int top, size;
public:

	TStack()
	{
		stack = new T[100];
		top = -1;
		size = 100;
	}

	TStack(int n)
	{
		if (n < 0)
			throw "incorrect stack size";
		size = n;
		stack = new T[size];
		top = -1; 		
	}

	TStack(const TStack& a)
	{
		size = a.size;
		head = a.head;
		stack = new T[size];
		for (int i = 0; i < size; i++)
			stack[i] = a.stack[i];
	}

	~TStack()
	{
		delete[] stack;
	}

	void push(T A)
	{
		if ((top + 1) == size)
		{
			T* s = new T[size * 2];
			for (int i = 0; i < size; i++)
				s[i] = stack[i];
			delete[]stack;
			size = size * 2;
			stack = s;
		}
		stack[top+1] = A;
		top++;
	}

	bool IsEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	T pop()
	{
		if (IsEmpty()) 
			throw "Error: stack_is_empty";
		return stack[top--];
	}
	

	void clear()
	{
		delete[] stack;
		stack = new T[size];
		top = -1;
	}

	int GetSize()
	{
		return size;
	}

	T peek()
	{
		if (IsEmpty())
			throw "it is not possible to use peek with an empty stack";
		return stack[top];
	}
};

#endif