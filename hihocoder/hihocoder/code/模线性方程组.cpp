#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
long long a[10010], r[10010];

long long ex_gcd(long long n, long long m, long long& x, long long& y){
	if (m == 0){
		x = 1;
		y = 0;
		return n;
	}
	else{
		long long gcd = ex_gcd(m, n%m, x, y);
		long long temp = x;
		x = y;
		y = temp - n / m*y;
		return gcd;
	}
}


int main(){
	ifstream in("C:\\input.txt");
	int N;
	while (cin >> N){
		for (int i = 1; i <= N; ++i){
			cin >> a[i] >> r[i];
		}

		long long ta, tr, x, y, lcm;
		bool f = 1;
		ta = a[1];
		tr = r[1];
		for (int i = 2; i <= N; ++i){
			long long gcd = ex_gcd(ta, a[i], x, y);
			long long absr = r[i] - tr;
			if (absr % gcd){
				f = 0;
				break;
			}
			lcm = ta / gcd*a[i];
			a[i] /= gcd;
			absr /= gcd;
			tr = (ta*((x*(absr%a[i]) % a[i] + a[i]) % a[i]) + tr) % lcm;
			ta = lcm;
		}

		if (f){
			cout << (tr%ta + ta) % ta << endl;
		}
		else{
			cout << -1 << endl;
		}
	}


	return 0;
}