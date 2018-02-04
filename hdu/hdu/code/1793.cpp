#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
#define SUM(i,j) (sum[j]-sum[i-1])
int data[1010];
int sum[1010];
int dp[1010][1010];
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		for (int i = 0; i < N; ++i){
			int t;
			//in >> t;
			scanf("%d", &t);
		}
		sum[0] = 0;
		for (int i = 1; i <= N; ++i){
			//in >> data[i];
			scanf("%d", &data[i]);
			sum[i] = sum[i - 1] + data[i];
			dp[i][i] = 0;
		}
		for (int len = 2; len <= N;++len)
		for (int i = 1; i + len - 1 <= N; ++i){
			int j = i + len - 1;
			dp[i][j] = min(dp[i + 1][j]+SUM(i+1,j), dp[i][j - 1]+SUM(i,j-1));
			for (int k = i + 1; k < j;++k)
			if (dp[i][j] > dp[i][k - 1] + SUM(i, k - 1) + dp[k + 1][j] + SUM(k + 1, j))
				dp[i][j] = dp[i][k - 1] + SUM(i, k - 1) + dp[k + 1][j] + SUM(k + 1, j);
		}
		cout << dp[1][N] << endl;
	}
	return 0;
}