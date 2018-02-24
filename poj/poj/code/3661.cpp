#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M;
#define INF (1<<29)
int dp[10010][510];
bool vis[10010][510];
int data[10010];




int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		for (int i = 1; i <= N; ++i){
			cin >> data[i];
		}
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i <= N + 1; ++i){
			dp[i][0] = 0;
			vis[i][0] = 1;
		}
		for (int i = 1; i <= N+1; ++i)
		for (int j = 0; j <= M; ++j)
		if (vis[i][j]){
			if (j == 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (i + j <= N + 1){
				if (!vis[i + j][0]){
					vis[i + j][0] = 1;
					dp[i + j][0] = dp[i][j];
				}
				else if (dp[i][j]>dp[i + j][0])
					dp[i + j][0] = dp[i][j];
			}
			if (j<M){
				if (!vis[i + 1][j + 1]){
					vis[i + 1][j + 1] = 1;
					dp[i + 1][j + 1] = dp[i][j] + data[i];
				}
				else if (dp[i + 1][j + 1]<dp[i][j] + data[i])
					dp[i + 1][j + 1] = dp[i][j] + data[i];
			}
		}
		cout << dp[N+1][0] << endl;






	}



	return 0;
}