#include <iostream>


using namespace std;
int dp[10000][400];
int KKK = 100000000;
int main(){
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;
	dp[1][0] = 1;
	dp[2][1] = 1;
	dp[2][0] = 1;
	dp[3][1] = 1;
	dp[3][0] = 1;
	dp[4][1] = 1;
	dp[4][0] = 1;
	for (int i = 5; i < 10000; ++i){
		int k = dp[i - 1][0];
		for (int j = 1; j <= k; ++j){
			dp[i][j] += dp[i - 1][j] + dp[i - 2][j] + dp[i - 3][j] + dp[i - 4][j];
			if (dp[i][j] >= KKK){
				dp[i][j + 1] = dp[i][j]/KKK;
				dp[i][j] %= KKK;	
			}	         
		}
		if (dp[i][k + 1])
			k++;
		dp[i][0] = k;
	}
	int N;
	while (cin >> N){
		int len = dp[N][0];
		printf("%d", dp[N][len]);
		for (int i = len-1; i >= 1; --i)
			printf("%08d", dp[N][i]);
		cout << endl;
	}
		

	return 0;
}