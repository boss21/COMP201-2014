#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	vector <int> stack;
	string token;
	char *end;
	int ans, left, right;
	do 
	{
		cin >> token;

		if (token == "+")
		{
			right = stack.back();
			stack.pop_back();
			left = stack.back();
			stack.pop_back();
			ans = left + right;
			stack.push_back(ans);
		}
		else if (token == "-")
		{
			right = stack.back();
			stack.pop_back();
			left = stack.back();
			stack.pop_back();
			ans = left - right;
			stack.push_back(ans);
		}
		else if (token == "*")
		{
			right = stack.back();
			stack.pop_back();
			left = stack.back();
			stack.pop_back();
			ans = left * right;
			stack.push_back(ans);
		}
		else if (token == "/")
		{  // ex. 10 2 /
			right = stack.back(); //  2
			stack.pop_back(); 
			left = stack.back(); // 10
			stack.pop_back(); 
			ans = left / right; // 10 / 2
			stack.push_back(ans); // 5
		}
		else if (token == ".")
		{
			break;
		}
		else
		{
			stack.push_back(strtol(token.c_str(), &end, 10));
		}
		} while (token != ".");
	for (int i = 0; i < stack.size(); i++)
	{
		cout << stack[i] << endl;
	}
	return 0;
}