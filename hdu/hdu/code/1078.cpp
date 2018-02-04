#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[110][110];
int dp[110][110];
int dirs[2][2] = { 1, 0, 0, 1 };
bool vis[110][110];
int main(){
	ifstream in("C:\\temp.txt");
	int N, K;
	while (in >> N >> K&&N>=0){
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j)
			in >> data[i][j];
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		int mmax = 0;
		dp[0][0] = data[0][0];
		vis[0][0] = 1;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j)
		if (vis[0][0]){
			if (dp[i][j]>mmax)
				mmax = dp[i][j];
			for (int k = 1; k <= K; ++k)
			for (int d = 0; d < 2; ++d){
				int nextx, nexty;
				nextx = i + dirs[d][0] * k;
				nexty = j + dirs[d][1] * k;
				if (nextx < N&&nexty < N&&data[i][j] < data[nextx][nexty]){
					vis[nextx][nexty] = 1;
					if (dp[nextx][nexty] < dp[i][j] + data[nextx][nexty])
						dp[nextx][nexty] = dp[i][j] + data[nextx][nexty];
				}
			}
		}
		cout << mmax << endl;
		cout << dp[0][0];
	}
	return 0;
}