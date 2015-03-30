#include <iostream>

using namespace std;

int main()
{
	int a = 2;
	int b=0;
	int* p = &b;
	p = a + (p+b);
	
	cout << p;
	
	return 0;
}