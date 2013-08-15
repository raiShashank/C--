#include <iostream>
using namespace std;

int main()
{
	int val2 = 0;
	int foo = 999;
	int &ref1 = foo;
	cout << foo << " " << ref1 << endl;
	ref1++;
	cout << foo << " " << ref1 << endl;
	int &ref2 = ref1;
	ref2++;
	cout << foo << " " << ref1 << " " << ref2 << endl;
	cout << &foo << " " << &ref1 << " " << &ref2 << " " << &val2 << endl;
	
	ref1 = val2;
	ref1++;
	cout << foo << " " << ref1 << " " << ref2 << " " << val2 << endl;
	cout << &foo << " " << &ref1 << " " << &ref2 << " " << &val2 << endl;
}

/*
The following statement might seem to be redirecting ref1 to be an alias for
val2.  The code compiles and runs; so what is happening?

    ref1 = val2;

The program output shows that foo, ref1 and ref2 still refer to the same
address, a different address than val2.  

The statement actually causes the variable referred to by ref1 to be assigned
the value contained in val2.  The output shows that none of the addresses have
changed, and that the variable aliased by foo, ref1 and ref2 now contains
(the contents of val2) + 1.

So, an assignment through a reference can be made as many times as necessary,
but a reference relationship can only be established once while the relevant
code is in scope.
*/
