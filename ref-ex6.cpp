#include <iostream>
using namespace std;

void swap(int &p1,int &p2)
{
	int temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}
int &refTest(int &param)
{
	return param;
}
int main()
{
	int val1 = 0,val2 = 0;
	int val3 = 33,val4 = 44;
	int val5 = 1818,val6 = 3636;
	short val7 = 2718,val8 = 3141;
	
	cout << val5 << " " << val6 << endl;
	swap(val5,val6);
	cout << val5 << " " << val6 << endl;
	
	cout << val7 << " " << val8 << endl;
	swap(val7,val8);
	cout << val7 << " " << val8 << endl;
	
	swap((int)val7,(int)val8);
	cout << val7 << " " << val8 << endl;

	val1 = refTest(val4);
	cout << val1 << " " << val4 << endl;
	
	refTest(val2) = val3;
	cout << val2 << " " << val3 << endl;
	
	return 0;
}
