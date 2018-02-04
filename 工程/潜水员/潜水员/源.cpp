#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int dp[44][160];
int M, N;
int main(){
	ifstream in("C:\\gas4.in");
	in >> M >> N;
	int K;
	in >> K;
	int o, n, w;
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int k = 0; k < K; ++k){
		in >> o >> n >> w;
		for (int i = 2*M; i >=o;--i)
		for (int j = 2*N; j >=n; --j)
		if (dp[i-o][j-n] >= 0){
			if (dp[i][j] >= 0)
				dp[i][j] = min(dp[i][j], dp[i-o][j-n] + w);
			else
				dp[i][j] = dp[i-o][j-n] + w;
		}
	}
	int ans = INT_MAX;
	for (int i = M; i <= 2*M;++i)
	for (int j = N; j <= 2*N;++j)
	if (dp[i][j] >= 0)
		ans = min(ans, dp[i][j]);
	cout << ans << endl;
	return 0;
}
