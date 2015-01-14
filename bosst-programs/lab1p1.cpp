#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifs;
	ifs.open(argv[1]);
	if (ifs.fail())
	{
		cout << "Could'nt open " << argv[1] << endl;
		return 1;
	}
	cout << "x\tx^2\tCurrent Sum" << endl;
	cout << "=\t===\t===========" << endl;
	int n, s = 0;
	while (ifs >> n)
	{
		cout << n << "\t" << n*n << "\t" << (s += n) << endl;
	}
	ifs.close();
	return 0;
}