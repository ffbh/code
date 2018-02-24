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

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


int n;
int a[1000010];


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}

LL mod = (LL)1e9 + 7;
LL fac[1000010], inv[1000010];

LL quick_mod(LL a,LL p){
	LL ret = 1;
	a %= mod;
	while (p){
		if (p & 1)
			ret = ret*a%mod;
		a = a*a%mod;
		p /= 2;
	}
	return ret;
}

LL C(int n, int m){
	return fac[n] * inv[m] % mod*inv[n - m] % mod;

}

LL cale(int k){
	LL large = fac[k];
	LL less = 1;
//	if (k+1<n)
		less = fac[n] * inv[k + 1] % mod;
	return large * less % mod;

}


int main(){


	fac[0] = 1;
	for (int i = 1; i<1000010; ++i)
		fac[i] = fac[i - 1] * i%mod;
	inv[1000009] = quick_mod(fac[1000009], mod - 2);
	for (int i = 1000008; i >= 0; --i)
		inv[i] = inv[i + 1] * (i + 1) % mod;



	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		sort(a + 1, a + n + 1);

		LL ans = 0;
		a[0] = -1;
		int pos = 1, K = n;
		while (pos <= n){
			int val = a[pos];
			int num = 0;
			while (a[pos] == val){
				pos++;
				num++;
			}
			
			if (val != a[n])
				ans = (ans + cale(K - 1)*num%mod * val % mod) % mod;
			K -= num;

		}

		cout << ans << endl;











	}


	return 0;
}





