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

int n, q;
string str;

int dp[100010][2];

void input(){
	in >> n >> q;
	in >> str;


}

LL mod = 1e9 + 7;
LL ddd[100010];


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	ddd[0] = 0;
	LL pp = 1;
	for (int k = 1; k<100010; ++k){
		ddd[k] = (ddd[k - 1] + pp) % mod;
		pp = pp * 2 % mod;
	}

	while (TEST_CASE-- > 0){
		input();

		str = '-' + str;

		dp[0][0] = dp[0][1] = 0;
		int len = str.length();
		len--;
		for (int i = 1; i <= len; ++i){
			if (str[i] == '0'){
				dp[i][0] = dp[i - 1][0] + 1;
				dp[i][1] = dp[i - 1][1];
			}
			else{
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][1] + 1;
			}
		}

		while (q--){
			int l, r;
			in >> l >> r;
			int v0 = dp[r][0] - dp[l - 1][0];
			int v1 = dp[r][1] - dp[l - 1][1];
			LL a1 = ddd[v1];
			LL a2 = a1 * ddd[v0] % mod;
			printf("%lld\n", (a1 + a2) % mod);

		}










	}


	return 0;
}





