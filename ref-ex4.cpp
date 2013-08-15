#include <iostream>
using namespace std;

class SomeClass
{
private:
	int private1,private2;
public:
	SomeClass()
	{
		private1 = private2 = 0;
	}
	void printPrivate()
	{
		cout << private1 << " " << private2 << endl;
	}
};
SomeClass &getClass1()
{
	SomeClass second;
	return second;
}
SomeClass &getClass2()
{
	SomeClass *second = new SomeClass();
	return *second;		//while returning references v return d actual object/here it is *address
}
int main()
{
	SomeClass &sc1 = getClass1();	//if a refernce isreturned,it is received by a reference,dough simple variable will also wrk but here if u say simply dat sc2 is a var,den delete &sc2 will cause prob,hence memory leak
	sc1.printPrivate();
	SomeClass sc2 = getClass2();
	sc1.printPrivate();
	sc2.printPrivate();
	
	delete &sc2;
	return 0;
}
/*
getClass1() returns a reference to an object declared on the stack; the object
is a local variable of that function.  When getClass1() returns, the local
variables are invalidated and the stack space they occupied is reclaimed.  This
error is analogous to returning a pointer to a function's local variable.

Note that sc1 attribute private2 is corrupt after the call to getClass2().
Since sc1 is a dangling reference, this is not surprising.  In addition to
data corruption, use of a dangling reference may cause program or system
crashes.

Because of the risk of misuse, some experts recommend never returning a
reference from a function or method.

Function getClass2 correctly returns a reference to a dynamic object, allocated
on the heap by new.  The function has to return a reference to what second 
points to, an odd bit of syntax.  The programmer has to remember to free the
returned object with delete when done with it.  Also, delete requires the
address of sc2, more unusual syntax.
*/
