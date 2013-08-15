#include <iostream>
using namespace std;

class SecondClass
{
private:
	int private1,private2;
public:
	SecondClass()
	{
		private1 = private2= 0;
	}
	void setPrivate(int p1,int p2)
	{
		private1 = p1;
		private2 = p2;
	}
	void printPrivate()
	{
		cout << private1 << " " << private2 << endl;
	}
};
class FirstClass
{
public:
	void valTest(int *ptr, SecondClass sec)
	{
		ptr++;
		sec.setPrivate(1234,1235);
	}
	void ptrTest(int **ptr, SecondClass *sec)
	{
		(*ptr)++;
		sec->setPrivate(5678,5679);
	}
	void refTest(int *&ptr,SecondClass &sec)
	{
		ptr++;
		sec.setPrivate(9998,9999);
	}
};
int main()
{
	int array[4] = {111,222,333,444};
	int *iptr = &array[1];
	FirstClass *first = new FirstClass();
	SecondClass second;
	cout << *iptr << endl;
	second.printPrivate();
	first->valTest(iptr, second);
	cout << *iptr << endl;
	second.printPrivate();
	first->ptrTest(&iptr, &second);
	cout << *iptr << endl;
	second.printPrivate();
	first->refTest(iptr,second);
	cout << *iptr << endl;
	second.printPrivate();
	delete first;
	return 0;
}
