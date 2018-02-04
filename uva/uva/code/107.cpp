#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
#define esp (1e-9)


int getN(double a,double b){
	for (int k = 1;; ++k){
		double N = pow(b, 1.0 / k);
		double ta = a;
		for (int j = 1; j <= k; ++j){
			ta /= (N + 1);
		}
		if (fabs(ta - 1) < esp)
			return N + 0.1;
	}
}



int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	int a, b;
	while (cin>>a>>b){
		if (a == 0 && b == 0){
			break;
		}
		if (a == 1 && b == 1){
			printf("0 1\n");
			continue;
		}
		int N = getN(a, b);
		int p = log(a) / log(N+1) + 0.1;
		long long ansA, ansB, ta, tb;
		ansA = ansB = 0;
		ta = tb = 1;
		for (int i = 1; i <= p; ++i){
			ansA += ta;
			ta *= N;
		}
		ta = a;
		tb = 1;
		double hh = ta;
		for (int i = 1; i <= p; ++i){
			ansB += ta*tb;
			tb *= N;
			hh /= (N + 1);
			ta = hh + 0.1;
		}
		ansB += b;
		cout << ansA << " " << ansB << endl;
	}

	return 0;
}