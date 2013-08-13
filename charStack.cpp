#include <iostream>
#include "charStack.h"
using namespace std;

CharStack::CharStack()
{
	elements = new char[INITIAL_CAPACITY];
	capacity = INITIAL_CAPACITY;
	count = 0;
}
CharStack::~CharStack()
{
	delete[] elements;
}

int CharStack::size()
{
	return count;
}
bool CharStack::isEmpty()
{
	return count == 0;
}
void CharStack::clear()
{
	count = 0;
}
void CharStack::push(char ch)
{
	if (count == capacity)
		expandCapacity();
	elements[count] = ch;
	++count;
	
}
void CharStack::expandCapacity()
{
	capacity *= 2;
	char *array = new char[capacity];
	int i = 0;
	for(i = 0; i < count ; ++i)
	{
		array[i] = elements[i];
	}
	delete[] elements;
	elements = array;
}
char CharStack::pop()
{
	if (isEmpty())
		cout << "pop:stack is empty\n";
	else
	{
		--count;
		return elements[count];
	}
}
char CharStack::peek()
{
	if (isEmpty())
		cout << "peek:Attempting 2 peek an empty stack\n";
	else
		return elements[count - 1];
}
int main()
{
	CharStack stack;
	stack.push('a');
	stack.push('b');
	stack.push('c');
	cout << stack.size();
	cout << stack.peek();
	cout << stack.pop() << "\n";
	cout << stack.pop() << "\n";
	cout << stack.pop() << "\n";
	return 0;
}
