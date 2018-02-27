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
#include <cassert>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


int n;

void input(){
	in >> n;


}

const int MMAX = (5e2) + 10;
LL mod = 1e9 + 7;
LL fac[MMAX], inv[MMAX];

LL quick_mod(LL a,LL p){
	a %= mod;
	LL ret = 1;
	while (p){
		if (p & 1)
			ret = ret*a%mod;
		a = a*a%mod;
		p /= 2;
	}
	return ret;
}
LL CNM(int n, int m){
	return fac[n] * inv[m] % mod*inv[n - m] % mod;
}


LL KTL(int k){
	LL all = CNM(2 * k, k);
	LL fail = CNM(2 * k, k + 1);
	return (all - fail + mod) % mod;
}

LL f[MMAX];
void Init(){
	fac[0] = 1;
	for (int i = 1; i < MMAX; ++i)
		fac[i] = fac[i - 1] * i%mod;
	inv[MMAX - 1] = quick_mod(fac[MMAX - 1], mod - 2);
	for (int i = MMAX - 2; i >= 0; --i)
		inv[i] = inv[i + 1] * (i + 1) % mod;
	f[0] = 1;
	for (int i = 1; i < MMAX; ++i)
		f[i] = KTL(i);



}



void add(LL& a,LL b){
	a %= mod;
	b %= mod;
	a += b;
	a %= mod;
	if (a < 0)
		a += mod;
}



int main(){
	Init();
	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();


		LL ans = 0;
		LL sum = 0;
		for (int i = n; i >= 1; --i){
			int deep = n - i;
			LL all = (sum + f[i] * f[deep] % mod * (deep+1) % mod) % mod;
			add(ans, all*i);
			sum = all;
		}
		cout << ans << endl;

		












	}


	return 0;
}





