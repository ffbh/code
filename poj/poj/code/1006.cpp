#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int a[3] = { 23, 28, 33 },M[3],inv[3],val[3];
int b[3], d;

int qm(int base, int p, int m){
	int ret = 1;
	while (p){
		if (p & 1)
			ret = (ret*base) % m;
		base = (base*base) % m;
		p /= 2;
	}
	return ret;
}

int cale(){
	int muls = 1;
	for (int i = 0; i < 3; ++i)
		muls *= a[i];
	for (int i = 0; i < 3; ++i){
		M[i] = muls / a[i];
	}
	//for (int i = 0; i < 3; ++i)
	//	inv[i] = qm(M[i], a[i] - 2, a[i]);
	inv[0] = 6;
	inv[1] = 19;
	inv[2] = 2;
	for (int i = 0; i < 3; ++i)
		val[i] = M[i] * inv[i] * (b[i]%a[i]);
	int sum = 0;
	for (int i = 0; i < 3; ++i)
		sum += val[i];
	return sum % muls;
}

int main(){
	ifstream in("C:\\input.txt");
	int CASE = 1;
	while (cin >> b[0] >> b[1] >> b[2] >> d&&b[0] != -1){
		int ans = (cale()-d+21252)%21252;
		if (ans == 0)
			ans = 21252;
		printf("Case %d: the next triple peak occurs in %d days.\n", CASE++, ans);


	}
















	return 0;
}