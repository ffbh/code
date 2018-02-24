#include <iostream>
#include <algorithm>
using namespace std;
int dp[1010][1010];
int main(){
	int T,N, M;
	scanf("%d", &T);
	int CASE = 1;
	while (T--){
		scanf("%d%d", &N, &M);
		for (int i = 1;i<=N;++i)
		for (int j = 1; j <= M; ++j){
			scanf("%d", &dp[i][j]);
			dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
		}
		printf("Scenario #%d:\n", CASE++);
		printf("%d\n\n", dp[N][M]);
	}
}