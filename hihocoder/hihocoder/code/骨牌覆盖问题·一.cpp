#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
const int mod = 19999997;
int N;
long long ma[2][2], ans[2];

void qm(int p){
	long long ret[2][2] = { 0 };
	for (int i = 0; i < 2; ++i)
		ret[i][i] = 1;
	long long tmp[2][2];
	while (p){
		if (p & 1){
			for (int i = 0; i < 2;++i)
			for (int j = 0; j < 2; ++j){
				tmp[i][j] = 0;
				for (int k = 0; k < 2; ++k){
					tmp[i][j] = (tmp[i][j] + ret[i][k] * ma[k][j]) % mod;
				}
			}
			memcpy(ret, tmp, sizeof(ret));
		}
		
		for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j){
			tmp[i][j] = 0;
			for (int k = 0; k < 2; ++k){
				tmp[i][j] = (tmp[i][j] + ma[i][k] * ma[k][j]) % mod;
			}
		}
		memcpy(ma, tmp, sizeof(ma));
		p /= 2;
	}
	memcpy(ma, ret, sizeof(ma));
}


int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	if (N <= 2){
		cout << N << endl;
	}
	else{
		N -= 2;
		ma[0][0] = 1;
		ma[0][1] = 1;
		ma[1][0] = 1;
		ma[1][1] = 0;
		qm(N);
		long long sum = (ma[0][0] * 2%mod + ma[1][0]) % mod;
		
		cout << sum << endl;
	}

	

	return 0;
}