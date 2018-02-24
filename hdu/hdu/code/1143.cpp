#include <iostream>
using namespace std;
int dp[33];
int N;
int dfs(int n){
	if (n > N+1)return 0;
	if (dp[n])
		return dp[n];
	dp[n] += 3 * dfs(n + 1);
	return dp[n] += 2*dfs(n + 2);
}




int main(){
	while (cin >> N&&N!=-1){
		memset(dp, 0, sizeof(dp));
		N /= 2;
		dp[N] = 1;
		cout << dfs(0) << endl;


	}


	return 0;
}

