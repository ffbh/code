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


int n, m, K;
string s[510];

void input(){
	in >> n >> m >> K;
	for (int i = 1; i <= n; ++i)
		in >> s[i];


}

int g[510][510];

int cale(int k){
	vector<int> lf, rt;
	int num = 0;
	for (int i = 0; i < m;++i)
	if (s[k][i] == '1'){
		num++;
		lf.push_back(i);
		rt.push_back(i);
	}
	reverse(rt.begin(), rt.end());
	if (num == 0){
		for (int i = 0; i <= m; ++i)
			g[k][i] = 0;
		return 0;
	}
	else{
		int len = lf.back() - lf[0] + 1;
		for (int i = num; i <= m; ++i)
			g[k][i] = len;
		g[k][0] = 0;
		for (int i = 1; i < num; ++i){
			for (int j = 0; j <= i; ++j){
				int l = j, r = i - j;
				int ldel = lf[j] - lf[0];
				int rdel = rt[0] - rt[r];
				g[k][i] = max(g[k][i], ldel + rdel);
			}
		}
		return len;
	}

}

int dp[510][510];

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		
		int sum = 0;
		for (int i = 1; i <= n; ++i)
			sum += cale(i);

		dp[0][0] = 0;
		for (int i = 0; i <= n; ++i){
			for (int j = 0; j <= K; ++j)
			for (int k = 0; k <= m; ++k){
				if (j + k <= K){
					dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + g[i + 1][k]);
				}
			}
		}
		cout << sum - dp[n][K] << endl;












	}


	return 0;
}





