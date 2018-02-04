#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	int a, b;
	double K = (sqrt(5.0) + 1) / 2;
	while (cin >> a >> b){
		if (a > b)
			swap(a, b);
		int k = b - a;
		if (int(k*K) == a)
			cout << 0 << endl;
		else
			cout << 1 << endl;
	
		
	}

	return 0;
}