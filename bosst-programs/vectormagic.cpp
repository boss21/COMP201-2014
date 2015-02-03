#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {

	vector <long long> numbers;
	for (int i = 0; i < 50; i++) {
		cout << "size: " << numbers.size() << " capacity " << numbers.capacity() << endl;
		numbers.push_back(pow(2,i));
		//numbers[i] = (pow(2,i));
	}
	for (int i = 0; i < 50; i++) {
		cout << numbers[i] << endl;
	}
	return 0;
}