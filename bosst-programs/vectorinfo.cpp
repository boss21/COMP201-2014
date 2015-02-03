#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
vector <string> words;
string word;
// read in words until were done
while (cin >> word) {
if (word == "done") {
break;
}
words.push_back(word);
}
// barf out words in reverse
while (words.size() > 0)
{
cout << words.back() << endl;
words.pop_back();
}
return 0;
}