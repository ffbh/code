#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct Road{
	int to;
	int v;
};
vector<Road> vi[1010];
int dp[1010];
int pace[1010];
bool vis[1010];
int N, M;

bool OK(int a, int b, int c, int d){
	if (a == c)return b != d;
	else if (a == d)return b != c;
	return 1;
}
int Djls(int a,int b){
	for (int i = 0; i <= N; ++i)
		dp[i] = INT_MAX;
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	pace[1] = 0;
	for (int i = 0; i < vi[1].size(); ++i){
		int son = vi[1][i].to;
		if (OK(a, b, 1, son)){
			dp[son] = vi[1][i].v;
			pace[son] = 1;
		}
	}
	for (int k = 0; k < N - 1; ++k){
		int u=0;
		int mmin = INT_MAX;
		for (int j = 1; j <= N; ++j)
 		if (!vis[j] && mmin>dp[j]){
			u = j;
			mmin = dp[j];
		}
		vis[u] = 1;
		int sz = vi[u].size();
		for (int j = 0; j < sz; ++j){
			int son = vi[u][j].to;
			int w = vi[u][j].v;
			if (!vis[son]&&dp[u] + w < dp[son]&&OK(a,b,u,son)){
				dp[son] = dp[u] + w;
				pace[son] = u;
			}
		}
	}
	return dp[N];
}

int main(){
	ifstream in("C:\\temp.txt");
	
	int a, b, c;
	Road rr;
	while (cin >> N >> M){
		for (int i = 0; i < 1010; ++i)
			vi[i].clear();
		
		memset(pace, 0, sizeof(pace));
		for (int i = 0; i < M; ++i){
		//	in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			if (a == b)continue;
			rr.to = b;
			rr.v = c;
			vi[a].push_back(rr);
			rr.to = a;
			vi[b].push_back(rr);
		}
		int ans = Djls(0, 0);
		int now, pre;
		now = N;
		while (pre = pace[now]){
			ans = max(ans, Djls(now, pre));
			now = pre;
		}
		cout << ans << endl;
	}

	return 0;
}