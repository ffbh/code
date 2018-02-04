
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;


long long mod = 1e9 + 7;

int N;
long long a[200010];
long long C[1010][1010];

void InitC(){
	for (int i = 0; i < 1010; ++i)
		C[i][0] = 1;
	for (int i = 0; i < 1010; ++i)
		C[i][i] = 1;

	for (int i = 1; i < 1010;++i)
	for (int j = 1; j < i; ++j)
		C[i][j] = (C[i - 1][j-1] + C[i - 1][j]) % mod;


}


/*void del(){
	for (int i = 1; i + 2000 <= N; ++i){
		long long tmp = 0;
		int d = 0;
		for (int j = i; j <= i + 2000; j += 2, d++){
			tmp = (tmp + a[j] * C[1000][d] % mod) % mod;
		}
		a[i] = tmp;
	}
	N -= 2000;
}*/
long long fac[200010], inv[200010];
long long cale(int n,int m){
	return fac[n] * inv[m] % mod*inv[n - m] % mod;
}

void del(int p){
	int ca = p / 2;
	for (int i = 1; i + p <= N; ++i){
		long long tmp = 0;
		int d = 0;
		for (int j = i; j <= i + p; j += 2, d++){
			tmp = (tmp + a[j] * cale(ca, d) % mod) % mod;
		}
		a[i] = tmp;
	}
	N -= p;
}



long long q_mod(long long a,int p){
	long long ret = 1;
	while (p){
		if (p & 1)
			ret = ret*a%mod;
		a = a*a%mod;
		p /= 2;
	}
	return ret;
}

int main(){
	fac[0] = inv[0] = 1;
	fac[1] = inv[1] = 1;
	for (int i = 2; i < 200010; ++i){
		fac[i] = (fac[i-1] * i) % mod;
		inv[i] = q_mod(fac[i], mod-2);
	}

	//ifstream in("C:\\input.txt");
	istream& in = cin;

	

	in >> N;
	for (int i = 1; i <= N; ++i)
		in >> a[i];

	int k = N % 4;
	if (k == 0)
		k = 4;
	del(N - k);




	int flag = 0;
	while (N > 1){
		for (int i = 1; i < N; ++i){
			if (flag == 0){
				a[i] = (a[i] + a[i + 1]) % mod;
			}
			else{
				a[i] = (a[i] - a[i + 1]) % mod;
			}
			flag = 1 - flag;
		}
		N--;
	}

	cout << (a[1] + mod) % mod << endl;












	return 0;
}





