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


int n, m, k;
int s[100010], t[100010], d[100010];
LL w[100010];
int maxD;


void input(){
	in >> n >> m >> k;
	for (int i = 1; i <= k; ++i){
		in >> s[i] >> t[i] >> d[i] >> w[i];
		maxD = max(maxD, d[i]);
	}
}

vector<int> add[100010], del[100010];
pll V[100010];
map<LL, int> M;

LL dp[210][100010];
LL INF = 1e18;
int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		for (int i = 1; i <= k; ++i){
			add[s[i]].push_back(i);
			del[t[i] + 1].push_back(i);
		}

		for (int i = 1; i <= n; ++i){
			for (int ad : add[i]){
				LL val = w[ad] * (LL)1e6 + d[ad];
				M[val]++;
			}

			for (int de : del[i]){
				LL val = w[de] * (LL)1e6 + d[de];
				M[val]--;
			}
			while (!M.empty()){
				auto mmm = --M.end();
				if (mmm->second == 0)
					M.erase(--M.end());
				else{
					break;
				}
			}
			if (M.empty()){
				V[i] = mp(-1, -1);
			}
			else{
				LL val = (--M.end())->first;
				V[i] = mp(val / ((LL)1e6), val % ((LL)1e6));
			}
		}


		for (int i = 0; i < 210;++i)
		for (int j = 0; j < 100010; ++j)
			dp[i][j] = INF;
		
	
		dp[0][1] = 0;
		for (int i = 0; i <= m;++i)
		for (int j = 1; j <= n; ++j){
			if (dp[i][j] != INF){
				if (i == 0 && j == 5){
					int t = 0;
				}
				pll next = V[j];
				
				if (next.first == -1){
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
			//		ans = max(ans, dp[i][j + 1]);

				}
				else{
					dp[i+1][j + 1] = min(dp[i+1][j + 1], dp[i][j]);
					dp[i][next.second + 1] = min(dp[i][next.second + 1], dp[i][j] + next.first);

			//		ans = max(ans, dp[i + 1][j + 1]);
				//	ans = max(ans, dp[i][next.second + 1]);

				}
			}

		}

		LL ans = INF;
		for (int i = 0; i <= m; ++i){
			for (int dd = maxD + 1; dd >= 0; --dd){
				if (dp[i][dd] != INF){
					ans = min(ans, dp[i][dd]);
					break;
				}

			}
		}

		cout << ans << endl;













	}


	return 0;
}





