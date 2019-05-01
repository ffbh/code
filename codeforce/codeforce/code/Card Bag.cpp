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
#define FFLUAHALL 	fflush(stdin);fflush(stdout);

void _init(){



}

LL dp[5010][5010];
LL mod = 998244353;
int n;
int a[5010];
vector<int> V;

void input(){
	in >> n;
	for (int i = 1; i <= n; ++i){
		in >> a[i];
	}


}

LL inv[5010];

LL quick_mod(LL a,LL p){
	LL ret = 1;
	a %= mod;
	while (p){
		if (p & 1){
			ret = ret*a%mod;
		}
		a = a*a%mod;
		p /= 2;
	}
	return ret;
}

void add(LL& a,LL b){
	a %= mod;
	b %= mod;
	a += b;
	a %= mod;
	if (a < 0){
		a += mod;
	}
}

int main(){

	for (int i = 0; i<5010; ++i)
		inv[i] = quick_mod(i, mod - 2);

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		map<int, int> M;
		for (int i = 1; i <= n; ++i){
			M[a[i]]++;
		}
		V.push_back(0);
		for (auto p : M){
			V.push_back(p.second);
		}
		int N = V.size() - 1;
		dp[0][0] = 1;
		LL ans = 0;
		for (int i = 0; i < N; ++i)
		for (int j = 0; j <= n; ++j){
			if (dp[i][j]){
				int nn = V[i + 1];
				int rest = n - j;
				add(dp[i + 1][j], dp[i][j]);
				add(dp[i + 1][j + 1], dp[i][j] * nn %mod * inv[rest] % mod);
				if (nn >= 2){
					add(ans, dp[i][j] * nn %mod *(nn - 1) % mod*inv[rest] % mod*inv[rest - 1] % mod);
				}
			}
		}
		cout << ans << endl;
	}


	return 0;
}





