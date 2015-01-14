#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream ifs;
	ofstream ofs;
	ifs.open(argv[1]);
	if (ifs.fail())
	{
		cout << "Could'nt open " << argv[1] << endl;
		return 1;
	}
	ofs.open("output.txt");
	if (ofs.fail())
	{
		cout << "Could'nt open " << "output.txt" << endl;
		return 1;
	}
	ofs << "x\tx^2\tCurrent Sum" << endl;
	ofs << "=\t===\t===========" << endl;
	int n, s = 0;
	while (ifs >> n)
	{
		ofs << n << "\t" << n*n << "\t" << (s += n) << endl;
	}
	ifs.close();
	ofs.close();
	
	return 0;
}