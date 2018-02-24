#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int f[40];

int main(){
	ifstream in("C:\\temp.txt");
	f[0] = f[1] = 1;
	for (int i = 2; i < 40; ++i)
		f[i] = f[i - 1] + f[i - 2];
	int N;
	cout << f[0];




	return 0;
}