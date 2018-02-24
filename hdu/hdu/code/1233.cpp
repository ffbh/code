#include <iostream>
#include <fstream>
using namespace std;
int num[110][110];
bool map[110][110];
int dp[110];
bool vis[110];
int main(){
	//ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N&&N){
		memset(map,0, sizeof(map));
		memset(vis, 0, sizeof(vis));
		M = N*(N - 1) / 2;
		int a, b, c;
		for (int i = 0; i < M; ++i){
			//in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			num[a][b] = c;
			num[b][a] = c;
			map[b][a] = 1;
			map[a][b] = 1;
		}
		for (int i = 2; i <= N;++i)
		if (map[1][i])
			dp[i] = num[1][i];
		else dp[i] = INT_MAX;
		dp[1] = INT_MAX;
		vis[1] = 1;
		int ans = 0;
		for (int i = 1; i < N; ++i){
			int mmin=INT_MAX;
			int u;
			for (int k = 1; k <= N; ++k)
			if (mmin>dp[k]&&!vis[k]){
				mmin = dp[k];
				u = k;
			}
			ans += mmin;
			vis[u] = 1;
			for (int k = 1; k <= N; ++k)
			if (map[u][k]&&!vis[k]&&dp[k]>num[u][k]&&u!=k)
				dp[k] = num[u][k];
		}
		
		cout << ans << endl;

	
	}




	return 0;
}