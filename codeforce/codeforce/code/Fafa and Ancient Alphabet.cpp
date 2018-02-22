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
int a[100010], b[100010];


void input(){
	in >> n >> m;
	for (int i = 1; i <= n; ++i)
		in >> a[i];

	for (int i = 1; i <= n; ++i)
		in >> b[i];
}

LL mod = (LL)1e9 + 7;
LL fac[100010], inv[100010];

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



LL dfs(int pos){
	if (pos > n)
		return 0;



	if (a[pos] == 0 && b[pos] == 0){
		if (m == 1){
			return dfs(pos + 1)*inv[m] % mod;
		}
		else{
			return (dfs(pos + 1)*inv[m] % mod + (m - 1)*inv[2] % mod*inv[m]%mod) % mod;
		}
	}
	else if (a[pos] == 0){
		return (dfs(pos + 1)*inv[m] % mod + inv[m] * (m - b[pos]) % mod) % mod;
	}
	else if (b[pos] == 0){
		return (dfs(pos + 1)*inv[m] % mod + inv[m] * (a[pos] - 1) % mod) % mod;
	}
	else{
		if (a[pos] < b[pos])
			return 0;
		else if (a[pos]>b[pos])
			return 1;
		return dfs(pos + 1);
	}

}

int main(){
	fac[0] = 1;
	for (int i = 1; i<100010; ++i)
		fac[i] = i * fac[i - 1] % mod;
	inv[100009] = quick_mod(fac[100009], mod - 2);
	inv[0] = 1;
	for (int i = 100008; i >= 0; --i)
		inv[i] = inv[i + 1] * (i + 1) % mod ;
	for (int i = 100009; i >= 1; --i)
		inv[i] = inv[i] * fac[i - 1] % mod;
	
	

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		cout << dfs(1) << endl;
		













	}


	return 0;
}





