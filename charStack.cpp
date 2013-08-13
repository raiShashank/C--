#include <iostream>
#include "charStack.h"
using namespace std;

CharStack::CharStack()
{
	count = 0;
}
CharStack::~CharStack()
{
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
	if (count == MAX_STACK_SIZE)
		cout << "push:Stack is full\n";
	else
	{
		elements[count] = ch;
		++count;
	}
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
