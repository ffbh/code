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

ifstream in("C:\\input.txt");
//istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back

int n;
LL mod = 1e9 + 7;

int ok[510][510];

LL dp[510][510][510];

void input(){
	in >> n;
	for (int i = 1; i <= n;++i)
	for (int j = 1; j <= n; ++j)
		in >> ok[i][j];


}

LL dfs(int p,int l,int r){
	if (dp[p][l][r] != -1)
		return dp[p][l][r];

	if (l > r)
		return 1;
	LL& ref = dp[p][l][r];
	ref = 0;

	for (int i = l; i <= r; ++i){
		if (ok[p][i] == 0)
			continue;

		LL L1 = dfs(i, l, i - 1);
	//	LL L2 = dfs(p, l, i - 1);
		LL L2 = 0;
		LL R1 = dfs(i, i + 1, r);
		LL R2 = dfs(p, i + 1, r);
		
		LL L, R;

 		if (p == 1 && l == 2 && r == 4){
			int t = 0;
		}

		if (l > i - 1){
			L = 1;
		}
		else{
			L = (L1 + L2) % mod;
		}

		if (i + 1 > r){
			R = 1;
		}
		else{
			R = (R1 + R2) % mod;
		}
		ref = (ref + L*R%mod) % mod;
	}

	cout << p << " " << l << " " << r << " " << ref << endl;

	return ref;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		memset(dp, -1, sizeof(dp));
		cout << dfs(1, 2, n) << endl;












	}


	return 0;
}





