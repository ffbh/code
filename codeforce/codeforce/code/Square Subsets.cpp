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

int n;
LL h[100];
LL mod = 1e9 + 7;

LL fac[100010];
LL inv[100010];


LL qm(LL a,LL p){
	LL ret = 1;
	while (p){
		if (p % 2)
			ret = (ret*a) % mod;
		a = (a*a) % mod;
		p /= 2;
	}
	return ret;
}

int mask[100];
vector<int> prime({ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67 });

void Init(){
	fac[0] = 1;
	for (int i = 1; i < 100010; ++i)
		fac[i] = fac[i-1] * i%mod;

	inv[100009] = qm(fac[100009], mod - 2);
	for (int i = 100008; i >= 0; --i)
		inv[i] = inv[i + 1] * (i + 1) % mod;
	

	for (int i = 2; i <= 70; ++i){
		mask[i] = 0;
		int t = i;
		for (int j = 0; j < prime.size(); ++j){
			while (t % prime[j] == 0){
				t /= prime[j];
				mask[i] ^= (1 << j);
			}
		}
	}
}

void input(){
	in >> n;
	for (int i = 0; i < n; ++i){
		int t;
		in >> t;
		h[t]++;
	}
}


LL cale(int n,int m){
	return fac[n] * inv[m] % mod*inv[n - m] % mod;
}


LL num[100][2];
LL dp[2][(1 << 20) + 10];





int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;

	while (TEST_CASE-- > 0){
		Init();
		input();

		LL one = 1;
		for (int i = 1; i <= h[1]; ++i)
			one = one * 2 % mod;

	
		for (int i = 2; i <= 70; ++i){
			num[i][0] = 0;
			for (int j = 0; j <= h[i]; j += 2){
				num[i][0] = (num[i][0] + cale(h[i], j)) % mod;
			}
			num[i][1] = 0;
			for (int j = 1; j <= h[i]; j += 2){
				num[i][1] = (num[i][1] + cale(h[i], j)) % mod;
			}
		}

		dp[1][0] = 1;
		for (int i = 1; i <= 70; ++i){
			memset(dp[1 - (i % 2)], 0, sizeof(dp[1 - (i % 2)]));
			for (int j = 0; j < (1 << 20); ++j){
				int f = i % 2;
				int nf = 1 - f;
				
				if (dp[f][j]){
					dp[nf][j] = (dp[nf][j] + dp[f][j] * num[i + 1][0] % mod) % mod;
					dp[nf][j^mask[i + 1]] = (dp[nf][j^mask[i + 1]] + dp[f][j] * num[i + 1][1] % mod) % mod;
				}
			}
		}

		LL ans = dp[70%2][0];
		ans *= one;
		ans %= mod;
		ans--;
		ans += mod;
		ans %= mod;
		cout << ans << endl;
		













	}


	return 0;
}





