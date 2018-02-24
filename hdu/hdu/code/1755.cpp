#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M;
int data[10];
bool vis[10];
int dp[110][110];
void dfs(int pre, int n){
	if (n == N){
		for (int k = 2; k < 100; ++k){
			int mod = pre%k;
			if (!dp[k][mod])
				dp[k][mod] = pre;
		}
		return;
	}
	for (int i = 0; i < N;++i)
	if (!vis[i]){
		if (pre == 0 && data[i] == 0)
			continue;
		vis[i] = 1;
		dfs(pre * 10 + data[i], n + 1);
		vis[i] = 0;
	}
}


int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i)
			cin >> data[i];
		sort(data, data + N);
		dfs(0, 0);
		while (M--){
			int X, K;
		//	in >> X >> K;
			scanf("%d%d", &X, &K);
			int mod = K - X%K;
			mod %= K;
			if (dp[K][mod])
				cout << dp[K][mod] << endl;
			else
				cout << "None" << endl;
		}
	}
	return 0;
}