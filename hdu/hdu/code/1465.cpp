#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int f[21];
	f[2] = 1;
	f[3] = 2;
	for (int i = 4; i <= 20; ++i)
		f[i] = (i - 1)*(f[i - 1] + f[i - 2]);
	while (cin >> N)
		cout << f[N] << endl;

	return 0;
}