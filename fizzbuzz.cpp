#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	for (i = 1; i <= 100; i++)
	{
		if (((i % 3) == 0) && ((i % 5) == 0))
		{
			cout << "FizzBuzz" << endl;
		}
		else if ((i % 5) == 0)
		{
			cout << "Buzz" << endl;
		}
		else if ((i % 3) == 0)
		{
			cout << "Fizz" << endl;
		}
		else
		{
			cout << i << endl;;
		}
	}
	system("pause");
	return 0;
}
