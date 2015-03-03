#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> v;
	string next;
	
	cout << "Enter words (end with CTRL-D): ";
	while ( cin >> next )
	{
		if (next == "A")
		{
			break;
		}
		v.push_back( next );
	}
	
	for ( int i=( v.size()-1 ); i>=0; i-- )
	{
		cout << v[i] << " ";
	}
	cout << endl;
	
	return 0;
}

