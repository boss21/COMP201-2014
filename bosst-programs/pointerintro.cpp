#include <iostream>

using namespace std;
// g++ -g pointerinfo.cpp -o pointerinfo.exe
// gdb pointerinfo.exe
int main(int argc, char *argv[])
{
	// declaring a variable allocates space in memory for that variable
	// that memory is in the stack
	int variable;
	// let's initialize it. this just sets the value
	variable = 500;
	// declaring a pointer alo declares a variable// that memory is also on the stack
	int* pointer;
	// initialize the pointer to where variable happens to be
	pointer = &variable;
	// *pointer de-references the pointer (we get what it's pointing at)
	cout << *pointer << endl;
	return 0;
}