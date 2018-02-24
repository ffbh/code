#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int gcd(int m, int n){
	if (m%n == 0)
		return n;
	else
		return gcd(n, m%n);

}

int main(){
	ifstream in("C:\\temp.txt");
	double L, sx, sy, px, py;
	while (cin >> L >> sx >> sy >> px >> py&&L){
		if (fabs(px) > L || fabs(py) > L){
			cout << "Out Of Range" << endl;
			continue;
		}
		if (sx == px){
			if (fabs(sy - py) >= 2)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
			continue;
		}
		if (sy == py){
			if (fabs(sx - px) >= 2)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
			continue;
		}
		int X = abs(sx - px);
		int Y = abs(sy - py);
		if (X < Y)
			swap(X, Y);
		if (gcd(X, Y) == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}