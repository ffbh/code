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

LL dp[2010][2010];
LL mod = (LL)1e9 + 7;

void input(){
	in >> m >> n;


}


int main(){

	dp[0][1] = 1;
	for (int i = 0; i<2008;++i)
	for (int j = 1; j<2010; ++j){
		if (dp[i][j]){
			for (int k = 1; k*j < 2010; k++){
				dp[i + 1][k*j] += dp[i][j];
				dp[i + 1][k*j] %= mod;
			}
		}
	}

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		LL sum = 0;
		for (int i = 1; i <= m; ++i)
			sum = (sum + dp[n][i]) % mod;
		cout << sum << endl;














	}


	return 0;
}





