#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
bool vis[42][42];
int dp[42][42];
int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		memset(vis, 0, sizeof(vis));
		memset(dp, 0, sizeof(dp));
		int x, y;
		cin >> x >> y;
		vis[y+1][x+1] = 1;
		cin >> x >> y;
		vis[y+1][x+1] = 1;
		dp[1][1] = 1;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j){
			if (!(vis[i][j] && vis[i][j - 1]))
				dp[i][j] += dp[i][j - 1];
			if (!(vis[i][j] && vis[i-1][j]))
				dp[i][j] += dp[i-1][j];
		}
		cout << dp[N][M] << endl;
	}
	return 0;
}