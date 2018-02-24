#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		int a, b, c;
		a = N / 2;
		N -= a;
		b = N * 2 / 3;
		N -= b;
		c = N;
		cout << ceil(double(a) / 10) + ceil(double(b) / 10) + ceil(double(c) / 10) << endl;


	}





	return 0;
}