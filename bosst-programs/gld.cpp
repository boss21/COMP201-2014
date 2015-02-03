#include <iostream>
// global variables/constants ( allocated with the program)
// local variables/constats ( allocated on the stack)
// dynamically allocated data (allocated by request on the heap)
using namespace std;
int main()
{
	int number, product;
	cout << "Hey, how many ints do you want? ";
	cin >> number;
	product = 1;
	
	// ask the operating system for some memory
	int * array = new int[number];
	
	for (int i = 0; i < number; i++)
	{
		cout << "number: ";
		cin >> array[i];
	}
	for (int i = 0; i < number; i++)
	{
		product *= array[i];
	}
	delete array;
	cout << product << endl;
	return 0;
}