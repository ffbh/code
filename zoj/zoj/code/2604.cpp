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




void input(){



}

LL dp[110][60][60];

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		dp[0][0][0] = 1;
		for (int i = 0; i <= 100;++i)
		for (int j = 0; j <= 50;++j)
		for (int k = 0; k <= j; ++k){
			if (dp[i][j][k] == 0)
				continue;
			int ni, nj, nk;
			ni = i + 1;
			nk = k + 1;
			nj = max(j, nk);
			dp[ni][nj][nk] += dp[i][j][k];

			if (k > 0){
				ni = i + 1;
				nj = j;
				nk = k - 1;
				dp[ni][nj][nk] += dp[i][j][k];
			}
		}

		int n, k;
		int CASE = 1;
		while (in >> n >> k){
			if (n == 0 && k == 0)
				break;
			printf("Case %d: %lld\n",CASE++, dp[2 * n][k][0]);

		}












	}


	return 0;
}





