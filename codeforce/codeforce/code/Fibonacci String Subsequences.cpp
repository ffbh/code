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

const LL mod = 1e9 + 7;

LL dp[110][110][110][4];//0 L 1 R 2 all 3 nothing
string str;
int n, x;
void input(){
	in >> n >> x;
	in >> str;


}

LL pl[110];

void add(LL& a, LL b){
	a %= mod;
	b %= mod;
	a += b;
	a %= mod;
	if (a < 0)
		a += mod;
}

LL dfs(int l, int r, int k,int f){
	assert(l <= r);
	LL& ref = dp[l][r][k][f];
	if (ref != -1)
		return ref;
	ref = 0;

	if (k == 0){
		if (l == r && str[l] == '0' && f == 2){
			ref = 1;
		}
		else{
			ref = 0;
		}
	}
	else if (k == 1){
		if (l == r && str[l] == '1'&&f == 2){
			ref = 1;
		}
		else{
			ref = 0;
		}
	}
	else{
	/*	if (l == r&&r == 0 && k == 3){
			int t = 0;
		}*/
		if (f == 0){
			add(ref, 1 * dfs(l, r, k - 2, 0));
			add(ref, (pl[k - 1] - 1)*dfs(l, r, k - 2, 0));
			add(ref, (pl[k - 1] - 1)*dfs(l, r, k - 2, 2));

			for (int i = l; i < r; ++i){
				ref = (ref + dfs(l, i, k - 1,0)*dfs(i + 1, r, k - 2,2) % mod) % mod;
			}

			add(ref, dfs(l, r, k - 1, 0) * 1);
		}
		else if (f == 1){
			add(ref, 1 * dfs(l, r, k - 2, 1));

			for (int i = l; i < r; ++i){
				          
				ref = (ref + dfs(l, i, k - 1, 2)*dfs(i + 1, r, k - 2, 1) % mod) % mod;
			}
			add(ref, dfs(l, r, k - 1, 1)*pl[k - 2]);
			add(ref, dfs(l, r, k - 1, 2)*(pl[k - 2] - 1));
			
		}
		else if (f == 2){
			add(ref, 1 * dfs(l, r, k - 2, 2));
			for (int i = l; i < r; ++i){
	     		ref = (ref + dfs(l, i, k - 1, 2)*dfs(i + 1, r, k - 2, 2) % mod) % mod;
			}
			add(ref, dfs(l, r, k - 1, 2 ) * 1);
		}
		else{
			add(ref, dfs(l, r, k - 1, 3) * pl[k - 2]);
			add(ref, dfs(l, r, k - 1, 0) * (pl[k - 2] - 1));
			for (int i = l; i < r; ++i){
				ref = (ref + dfs(l, i, k - 1, 0)*dfs(i + 1, r, k - 2, 1) % mod) % mod;
			}
			add(ref, (pl[k - 1]-1) * dfs(l, r, k - 2, 1));
			add(ref, pl[k - 1] * dfs(l, r, k - 2, 3));
		}

	}
	return ref;
}




int main(){

	pl[0] = pl[1] = 2;
	for (int i = 2; i<110; ++i)
		pl[i] = pl[i - 1] * pl[i - 2] % mod;

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		memset(dp, -1, sizeof(dp));

		cout <<( dfs(0, str.length() - 1, x, 0) + dfs(0, str.length() - 1, x, 1)
			+ dfs(0, str.length() - 1, x, 2) + dfs(0, str.length() - 1, x, 3))%mod << endl;

		










	}


	return 0;
}





