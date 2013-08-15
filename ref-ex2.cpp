#include <iostream>
using namespace std;

struct pairStruct
{
	int first;
	int second;
};

class TestClass
{
public:
	void valTest(int p1,pairStruct p2)
	{
		p1 = 111;
		p2.first = 122;
		p2.second = 133;
	}
	void ptrTest(int *p1,pairStruct *p2)
	{
		*p1 = 244;
		p2->first = 255;
		p2->second = 266;
	}
	void refTest(int &p1, pairStruct &p2)
	{
		p1 = 377;
		p2.first = 388;
		p2.second = 399;
	}
};
int main()
{
	int num = 0;
	pairStruct pair;
	TestClass test;
	pair.first = pair.second = 0;
	test.valTest(num,pair);
	cout << num << " " << pair.first << " " << pair.second << endl;
	test.ptrTest(&num,&pair);
	cout << num << " " << pair.first << " " << pair.second << endl;
	test.refTest(num,pair);
	cout << num << " " << pair.first << " " << pair.second << endl;
	return 0;
}
