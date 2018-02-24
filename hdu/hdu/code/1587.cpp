#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[10010];
int price[10010];
int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= N; ++i)
			scanf("%d", &price[i]);
	

		for (int k = 1; k <= N; ++k)
		for (int i = price[k]; i <= M;++i)
		if (dp[i - price[k]] + 1 > dp[i])
			dp[i] = dp[i - price[k]] + 1;

		int ans = INT_MIN;
		for (int i = 1; i <= M;++i)
		if (ans < dp[i])
			ans = dp[i];
		cout << ans << endl;

	}

	return 0;
}