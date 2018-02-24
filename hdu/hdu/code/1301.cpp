#include <iostream>
//#include <fstream>

using namespace std;
int map[30][30];
bool vis[30];
int dp[30];

int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	char c,t;
	int k,tt;
	while (cin >> N&&N>0){
		for (int i = 0; i < 30; ++i)
			dp[i] = INT_MAX;
		for (int i = 0; i < 30;++i)
		for (int j = 0; j < 30; ++j)
			map[i][j] = INT_MAX;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N - 1; ++i){
			//in >> c >> k;
			cin >> c;
			scanf("%d",&k);
			for (int j = 0; j < k; ++j){
		//	in >> t >> tt;
				cin >> t;
				scanf("%d", &tt);
				map[c - 'A'][t - 'A'] = map[t - 'A'][c - 'A'] = tt;
			}
		}

		for (int i = 0; i < N;++i)
			dp[i] = map[0][i];
		vis[0] = 1;
		int ans = 0;
		for (int i = 1; i < N; ++i){
			int u;
			int mmin = INT_MAX;
			for (int j = 0; j < N; ++j)
			if (!vis[j]&&dp[j]<mmin){
				u = j;
				mmin = dp[j];
			}
			vis[u] = 1;
			ans += mmin;
			for ( k = 0; k < N;++k)
			if (!vis[k] && dp[k]>map[u][k])
				dp[k] = map[u][k];
		}
		cout << ans << endl;
	
	
	
	}

	return 0;
}