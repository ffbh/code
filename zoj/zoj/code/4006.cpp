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

int n, m;

LL mod = 1e9 + 7;

LL fac[100010], inv[100010];

LL fac2[100010], fac4[100010];

LL quick_mod(LL a,LL p){
	a %= mod;
	LL ret = 1;
	while (p){
		if (p & 1)
			ret = ret * a%mod;
		a = a*a%mod;
		p /= 2;
	}
	return ret;
}

void input(){
	in >> n >> m;



}

LL CMD(int n,int m){
	return fac[n] * inv[m] % mod*inv[n - m] % mod;
}

bool judge(int aim,int move){
	if (abs(aim) > move)
		return 0;
	if ((move - abs(aim)) % 2 == 1)
		return 0;
	return 1;
}

int main(){
	fac[0] = 1;
	for (int i = 1; i < 100010; ++i)
		fac[i] = fac[i - 1] * i%mod;
	inv[100009] = quick_mod(fac[100009], mod - 2);

	for (int i = 100008; i >= 0; --i)
		inv[i] = inv[i + 1] * (i + 1) % mod;

	
	LL inv2 = quick_mod(2, mod - 2);
	LL inv4 = quick_mod(4, mod - 2);

	fac2[0] = fac4[0] = 1;
	for (int i = 1; i<100010; ++i){
		fac2[i] = fac2[i - 1] * inv2 % mod;
		fac4[i] = fac4[i - 1] * inv4 % mod;
	}

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		m = abs(m);

		LL ans = 0;
		for (int i = 0; i <= n; ++i){
			if (judge(m, n - i)){
				LL nomove = fac2[i];
				int ll = ((n - i) - m) / 2;
				int rr = n - i - ll;
				LL p = nomove * fac4[n - i] % mod;
			//	LL p = 1;
				LL pp = CMD(n, ll)*CMD(n - ll, rr) % mod;
				ans = (ans + pp *p%mod) % mod;
			}
		}

		cout << (ans + mod) % mod << endl;

	}


	return 0;
}





