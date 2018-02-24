#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define INF (-88888888)
int N, M;
int data[110][110];
int sum[110][110];
int dp[110][110];

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		cin >> N >> M;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j){
			cin >> data[i][j];
			dp[i][j] = INF;
		}
		for (int i = 1; i <= M; ++i)
			sum[1][i] = data[1][i];
		for (int i = 2; i <= N;++i)
		for (int j = 2; j <= M; ++j)
			sum[i][j] = sum[i - 1][j] + data[i][j];
		dp[1][1] = data[1][1];
		for (int i = 2; i <= N; ++i)
			dp[i][1] = dp[i - 1][1] + data[i][1];
		for (int j = 2; j <= M;++j)
		for (int i = 1; i <= N; ++i){
 			for (int k = 1; k < i;++k)
			if (dp[i][j] < dp[k][j-1] + sum[i][j] - sum[k-1][j])
				dp[i][j] = dp[k][j-1] + sum[i][j] - sum[k-1][j];
			if (dp[i][j] < dp[i][j-1] + data[i][j])
				dp[i][j] = dp[i][j-1] + data[i][j];
			for (int k = i + 1; k <= N;++k)
			if (dp[i][j] < dp[k][j-1] + sum[k][j] - sum[i-1][j])
				dp[i][j] = dp[k][j-1] + sum[k][j] - sum[i-1][j];
		}
		printf("Case #%d:\n", CASE++);
		cout << dp[1][M] << endl;
	}
	return 0;
}