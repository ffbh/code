#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int N;
long long a[1010], r[1010], M[1010], inv[1010];

long long ex_gcd(long long n,long long m,long long& x,long long& y){
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

long long gcd(long long a,long long b){
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

long long lcm(long long a,long long b){
	if (a < b)
		swap(a, b);
	return a / gcd(a, b)*b;
}


bool getInv(){
	long long x, y;
	for (int i = 1; i <= N; ++i){
		long long gcd = ex_gcd(M[i], a[i], x, y);
		if (r[i] % gcd != 0)
			return 0;
		r[i] /= gcd;
		inv[i] = x;
	}
	return 1;
}

int main(){
	ifstream in("C:\\input.txt");
	in >> N;
	for (int i = 1; i <= N; ++i){
		in >> a[i]>> r[i];
	}
	long long muls = 1;
	for (int i = 1; i <= N; ++i)
		muls *= a[i];
	for (int i = 1; i <= N; ++i)
		M[i] = muls / a[i];

	if (!getInv()){
		cout << -1 << endl;
	}
	else{
		long long sum = 0;
		for (int i = 1; i <= N; ++i)
			sum += M[i] * inv[i] * r[i];
		long long cm = 1;
		for (int i = 1; i <= N; ++i){
			cm = lcm(cm, a[i]);
		}
		cout << (sum % cm +cm)%cm<< endl;
	}


	return 0;
}