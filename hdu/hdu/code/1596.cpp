#include <iostream>
#include <fstream>
using namespace std;
double map[1010][1010];
double dp[1010];
bool vis[1001];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int a, b;
	while (cin >> N){
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j)
				scanf("%lf", &map[i][j]);
		//	in >> map[i][j];
		int K;
		cin >> K;
		for (int k = 0; k < K; ++k){
		//	in >> a >> b; 
			scanf("%d%d", &a, &b);
			if (a == b){
				cout << 1 << endl;
				continue;
			}
			memset(dp, 0, sizeof(dp));
			memset(vis, 0, sizeof(vis));
			for (int i = 1; i <= N;++i)
			if (map[a][i])
				dp[i] = map[a][i];
			else
				dp[i] = 0;
			vis[a] = 1;
			for (int i = 0; i < N - 1; ++i){
				int u;
				double mmax = 0;
				for (int j = 1; j <= N; ++j)
				if (dp[j]>mmax&&!vis[j]){
					mmax = dp[j];
					u = j;
				}
				vis[u] = 1;
				for (int j = 1; j <= N;++j)
				if (map[u][j] && u != j&&dp[j] < dp[u] * map[u][j])
					dp[j] = dp[u] * map[u][j];
			}
			if (dp[b])
				printf("%.3f\n", dp[b]);
			else
				printf("What a pity!\n");
		}
	}

	return 0;
}