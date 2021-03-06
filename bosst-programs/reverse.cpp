#include <iostream>
// C style string: char * (an array of characters)
#include <cstring>
// C++ style string: string
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
    string some_string;
    const char * c_string;
    // Read in a string from the user
    cin >> some_string;
	   // Demo command-line parameters
	for (int i = 1; i < argc; i++) {
        cout << argv[i] << endl;
    }
    // Convert fancy C++ string to C style string
    c_string = some_string.c_str();
    // Print it out is the same
    /*
	cout << some_string << endl;
    cout << c_string << endl;
	*/
    // Reverse the string (print it out backwards)
    for (int i = strlen(c_string) - 1; i >= 0; i--) {
        cout << c_string[i];
    }
    cout << endl;
    return 0;
}