#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int fbnq[25];

void Init(){
	fbnq[0] = 0;
	fbnq[1] = 1;
	fbnq[2] = 2;
	for (int i = 3; i < 25; ++i)
		fbnq[i] = fbnq[i - 1] + fbnq[i - 2];
}

int main(){
	ifstream in("C:\\temp.txt");
	Init();
	int T;
	cin >> T;
	int sum;
	while (T--){
		sum = 0;
		int N;
		cin >> N;
		for (int i = 24; i >= 1; --i){
			int div = N / fbnq[i];
			N %= fbnq[i];
			sum += fbnq[i - 1] * div;
		}
		cout <<  sum << endl;

	}
	return 0;
}