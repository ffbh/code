#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
int data[1010], N, M;
int sum[1010];
bool dp[10010];
bool slove(int m){
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= m; ++i){
		for (int j = N; j >= data[i]; --j)
		if (dp[j - data[i]])
			dp[j] = 1;
	}
	for (int i = N; i >= 0; --i){
		if (dp[i]){
			return sum[m] - i <= N;
		}
	}
}
int pace[10010];
bool vis[1010];
void dfs(int k){
	if (k == 0)
		return;
	dfs(k - data[pace[k]]);
	vis[pace[k]] = 1;
}
void print(int m){
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= m; ++i){
		for (int j = N; j >= data[i]; --j)
		if (!dp[j] && dp[j - data[i]]){
			dp[j] = 1;
			pace[j] = i;
		}
	}
	for (int i = N; i >= 0; --i){
		if (dp[i]){
			dfs(i);

			return;
		}
	}


}

int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	N *= 100;
	M = 1000;
	for (int i = 1; i < 1000; ++i){
		cin >> data[i];
		sum[i] = sum[i - 1] + data[i];
		if (data[i] == 0 || sum[i] >= N * 2){
			M = i;
			break;
		}
	}
	if (data[M] == 0)
		M--;
	int L = 0, R = M, ans = 0;
	while (L <= R){
		int m = (L + R) / 2;
		if (slove(m)){
			ans = m;
			L = m + 1;
		}
		else
			R = m - 1;
	}
	cout << ans << endl;
	print(ans);
	for (int i = 1; i <= ans;++i)
	if (vis[i])
		printf("port\n");
	else
		printf("starboard\n");
	
	return 0;
}