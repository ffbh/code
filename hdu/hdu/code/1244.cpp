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


int N, M;
LL a[1010], sum[1010];
int b[30];
LL dp[30][1010];
int vis[30][1010];
int main(){

	while (in >> N&&N){
		in >> M;
		for (int i = 1; i <= M; ++i){
			in >> b[i];
		}
		for (int i = 1; i <= N; ++i)
			in >> a[i];
		sum[0] = 0;
		for (int i = 1; i <= N; ++i)
			sum[i] = sum[i - 1] + a[i];

		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		dp[0][0] = 0;
		vis[0][0] = 1;
		for (int i = 0; i < M; ++i){

			for (int j = 0; j <= N; ++j){
				if (!vis[i][j])
					continue;
				int L = j + 1;
				int R = j + b[i + 1];
				if (R <= N){
					dp[i + 1][R] = max(dp[i + 1][R], dp[i][j] + sum[R] - sum[L - 1]);
					vis[i + 1][R] = 1;
				}
				dp[i][j + 1] = max(dp[i][j],dp[i][j+1]);
				vis[i][j + 1] = 1;

			}
		}
		LL ans = 0;
		for (int i = 1; i <= N;++i)
		if (vis[M][i])
			ans = max(ans, dp[M][i]);
		cout << ans << endl;


	}







	return 0;
}





