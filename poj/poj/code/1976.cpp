#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, K;
int data[50010];
int sum[50010];
int dp[4][50010];

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 1; i <= N; ++i)
			//in >> data[i];
			scanf("%d", &data[i]);
		cin >> K;
		for (int i = 1; i <= N; ++i)
			sum[i] = sum[i - 1] + data[i];
		for (int i = 1; i <= 3; ++i){
			int j = i*K;
			dp[i][j] = dp[i - 1][j - K] + sum[j] - sum[j - K];
			for (j++; j <= N; ++j)
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - K] + sum[j] - sum[j - K]);
		}
		cout << dp[3][N] << endl;
	}
	return 0;
}