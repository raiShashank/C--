#ifndef _charstack_h
#define  _charstack_h

class CharStack
{
public:
	CharStack();
	~CharStack();
	int size();
	bool isEmpty();
	void clear();
	void push(char ch);
	char pop();
	char peek();
private:
	static const int MAX_STACK_SIZE = 2;
	int count;
	char elements[MAX_STACK_SIZE];
};
#endif
