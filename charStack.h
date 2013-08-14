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
	//DISALLOW_COPYING(CharStack)
	void expandCapacity();

	static const int INITIAL_CAPACITY = 2;
	int capacity;
	int count;
	char *elements;
};
#endif
