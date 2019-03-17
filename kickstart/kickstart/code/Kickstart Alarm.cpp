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


LL N, K, x, y, C, D, E1, E2, F;
LL mod = (LL)(1e9 + 7);
void input(){
	in >> N >> K >> x >> y >> C >> D >> E1 >> E2 >> F;


}


LL quick_mod(LL a,LL p){
	a %= mod;
	LL ans = 1;
	while (p){
		if (p & 1)
			ans = ans* a%mod;
		a = a*a%mod;
		p /= 2;
	}
	return ans;
}

LL X[1000010], Y[1000010], A[1000010];

LL mulK[1000010];

void add(LL& a,LL p){
	a %= mod;
	p %= mod;
	a += p;
	a %= mod;
	if (a < 0)
		a += mod;
}

int main(){



	int CPP = 1;

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();




		X[1] = x;
		Y[1] = y;
		A[1] = (x + y) % F;

		//xi = (C ¡Á xi - 1 + D ¡Á yi - 1 + E1) modulo F.
		//	yi = (D ¡Á xi - 1 + C ¡Á yi - 1 + E2) modulo F.
		//	We define Ai = (xi + yi) modulo F, for all i = 1 to N.

		for (int i = 2; i <= N; ++i){
			X[i] = (C * X[i - 1] + D * Y[i - 1] + E1) % F;
			Y[i] = (D * X[i - 1] + C * Y[i - 1] + E2) % F;
			A[i] = (X[i] + Y[i]) % F;
		}

		mulK[1] = K;
		for (int i = 2; i <= N; ++i){
			LL V = (quick_mod(i, K + 1) - i + mod)%mod;
			LL div = quick_mod(i - 1, mod - 2);
			mulK[i] = V * div % mod;
		}

		LL ans = 0;
		LL mul = 0;
		for (int i = 1; i <= N; ++i){
			LL time = N - i + 1;
			add(mul, mulK[i]);
			add(ans, time * A[i] % mod*mul%mod);
		}

		printf("Case #%d: %lld\n", CPP++, ans);
	}


	return 0;
}





