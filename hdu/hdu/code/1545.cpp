#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
long long dp[80][10][10];// len max_1 max_0
const int MID = 7;



int main(){
	ifstream in("C:\\input.txt");
	int N, M;
	while (cin >> N >> M){
		memset(dp, 0, sizeof(dp));
		dp[1][1][0] = 1;
		dp[1][0][1] = 1;

		for (int i = 1; i < N; ++i)
		for (int j = 0; j <= M; ++j)
		for (int k = 0; k <= M; ++k)
		if (dp[i][j][k]){
			dp[i + 1][j + 1][max(k - 1, 0)] += dp[i][j][k];
			dp[i + 1][max(j - 1, 0)][k + 1] += dp[i][j][k];


		}
			
		long long ans = 0;
		for (int j = 0; j <= M; ++j)
		for (int k = 0; k <= M; ++k){
			ans += dp[N][j][k];
		}
		cout << ans << endl;
	}
	return 0;
}