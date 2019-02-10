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

LL mod = 1e9 + 7;
int n, l, r;
LL dp[200010][3];

int all[3], sub[3];

void input(){
	in >> n >> l >> r;


}


void add(LL & a1,LL a2){
	a1 %= mod;
	a2 %= mod;
	a1 += a2;
	a1 %= mod;
	if (a1 < 0){
		a1 += mod;
	}
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		all[0] = r / 3 + ((r % 3) >= 0 ? 1 : 0);
		all[1] = r / 3 + ((r % 3) >= 1 ? 1 : 0);
		all[2] = r / 3 + ((r % 3) >= 2 ? 1 : 0);

	
		sub[0] = (l-1) / 3 + (((l-1) % 3) >= 0 ? 1 : 0);
		sub[1] = (l-1) / 3 + (((l-1) % 3) >= 1 ? 1 : 0);
		sub[2] = (l-1) / 3 + (((l-1) % 3) >= 2 ? 1 : 0);

		for (int i = 0; i < 3; ++i){
			all[i] -= sub[i];
		}

		dp[0][0] = 1 ;
		for (int i = 1; i <= n; ++i){
			for (int j = 0; j <= 2; ++j){
				for (int k = 0; k <= 2; ++k){
					add(dp[i][j], dp[i - 1][(j - k + 3) % 3] * all[k]);
				}
			}
		}

		cout << dp[n][0] << endl;










	}


	return 0;
}





