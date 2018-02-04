#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int N, K;
int dp[11][110][110];
int dfs(int n, int l, int r){
	if (l == r)
		return l;
	if (dp[n][l][r] != -1)
		return dp[n][l][r];	
	dp[n][l][r] = 0;
	if (n == 1){
		for (int i = l; i <= r; ++i)
			dp[n][l][r] += i;
		return dp[n][l][r];
	}

	int ret1 = dfs(n, l + 1, r) + l;
	int ret2 = dfs(n - 1, l, r - 1) + r;
	int ret = min(ret1,ret2);
	for (int i = l+1; i <= r - 1; ++i){
		int t1 = dfs(n - 1, l, i - 1) + i;
		int t2 = dfs(n, i + 1, r) + i;
		if (ret > max(t1, t2)){
			ret = max(t1, t2);
		}

	}

	return dp[n][l][r] = ret;
}


int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	memset(dp, -1, sizeof(dp));
	while (T--){
		cin >> N >> K;
		cout << dfs(N,1,K) << endl;
	}
















	return 0;
}