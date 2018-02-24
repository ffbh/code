#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct Node{
	string s, e;
	int time;
};
struct Time{
	int to;
	int time;
};
Node num[1010];
vector<Time> vi[1010];
int dp[1010];
bool vis[1010];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	Time tt;
	string s;
	while (cin >> N&&N){
		for (int i = 0; i <= N; ++i)
			dp[i] = INT_MAX;
		for (int i = 0; i < 1010; ++i)
			vi[i].clear();
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= N; ++i){
		//	in >> num[i].time;
			scanf("%d", &num[i].time);
			cin >> s;
			num[i].s = s.substr(0, 4);
			num[i].e = s.substr(s.length() - 4);
		}
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N;++j)
		if (num[i].e == num[j].s&&i!=j){
			tt.time = num[i].time;
			tt.to = j;
			vi[i].push_back(tt);
		}
		vis[1] = 1;
		for (int i = 0; i < vi[1].size(); ++i){
			int son = vi[1][i].to;
			dp[son] = vi[1][i].time;
		}
		
		for (int k = 0; k < N - 1; ++k){
			int u=0;
			int mmin = INT_MAX;
			for (int i = 1; i <= N; ++i)
			if (!vis[i] && mmin>dp[i]){
				u = i;
				mmin = dp[i];
			}
			if (u == 0)break;
			vis[u] = 1;
			int sz = vi[u].size();
			for (int j = 0; j < sz; ++j){
				int son = vi[u][j].to;
				int ww = vi[u][j].time;
				if (!vis[son]&&dp[son]>dp[u] + ww)
					dp[son] = dp[u] + ww;
			}
		}
		if (dp[N] == INT_MAX)
			cout << -1 << endl;
		else
		cout << dp[N] << endl;
	}

	return 0;
}