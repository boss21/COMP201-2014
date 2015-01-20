#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
	vector<int> stack;
	int ans, left, right;
	char * end;
	
    for (int i = 1; i < argc; i++)
	{
		string token = string(argv[i]);
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
		{
			right = stack.back();
			stack.pop_back();
			left = stack.back();
			stack.pop_back();
			ans = left * right;
			stack.push_back(ans);
		} else {
			stack.push_back(strtol(token.c_str(), &end, 10));
		}
	}
	for (int i = 0; i < stack.size(); i++) {
		cout << stack[i] << endl;
	}
	return 0;
}
	