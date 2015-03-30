#include <iostream>
#include <string>

using namespace std;

// The swearing machine
int main()
{
	bool on = true;
int in[5];
cout << "Enter the numbers 1 - 5 in a random order" << endl;
for (int i = 0; i < 5; i++)
{
cin >> in[i];
}
cout << endl;
for (int i = 0; i < 5; i++)
{
	if(in[i] == 1)
	{
		cout << "fucker ";
	}
	else if (in[i] == 2)
	{
		cout << "shit ";
	}
	else if (in[i] == 3)
	{
		cout << "asshole ";
	}
	else if (in[i] == 4)
	{
		cout << "mother ";
	}
	else if (in[i] == 5)
	{
		cout << "bitch ";
	}
}
}	