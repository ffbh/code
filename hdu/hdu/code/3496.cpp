#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[110][1010];
bool vis[110][1010];
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		int N, M, K;
		cin >> N >> M >> K;
		for (int i = 0; i <= K; ++i)
			vis[0][i] = 1;
		while (N--){
			int a, b;
			cin >> a >> b;
			for (int i = M; i >= 1; --i)
			for (int j = K; j >= a; --j)
			if (vis[i - 1][j - a]){
				vis[i][j] = 1;
				if (dp[i][j] < dp[i - 1][j - a] + b)
					dp[i][j] = dp[i - 1][j - a] + b;
			}
		}

		if (vis[M][K])
			cout << dp[M][K] << endl;
		else
			cout << 0 << endl;

	}
	return 0;
}