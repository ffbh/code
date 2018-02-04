#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N, M;
int data[510];
int sum[510];
int dp[510][510];
int cost[510][510];

int main(){
	ifstream in("C:\\temp.txt");
	while(cin >> N >> M){
		for (int i = 1; i <= N; ++i){
			cin >> data[i];
			sum[i] = sum[i - 1] + data[i];
		}
		for (int i = 1; i <= N; ++i)
			dp[1][i] = sum[i] * (i - sum[i]);
		for (int i = 1; i <= N;++i)
		for (int j = i; j <= N; ++j)
			cost[i][j] = (j - i + 1 - sum[j] + sum[i - 1])*(sum[j] - sum[i - 1]);
		for (int i = 1; i <= N; ++i)
			dp[1][i] = sum[i] * (i - sum[i]);
		for (int i = 2; i <= M; ++i){
			dp[i][i] = 0;
			for (int j = i+1; j <= N; ++j){
				int tmp = INT_MAX;
				for (int k = i; k <= j; ++k){
					if (tmp>dp[i-1][k - 1] + cost[k][j])
						tmp = dp[i-1][k - 1] + cost[k][j];
				}
				dp[i][j] = tmp;
			}
		}
		cout << dp[M][N] << endl;
	}
	return 0;
}