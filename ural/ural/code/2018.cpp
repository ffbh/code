#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[2][2][310];

int main(){
	ifstream in("C:\\temp.txt");
	int N, A, B;
	cin >> N >> A >> B;
	dp[1][1][1] = dp[1][0][1] = 1;
	for (int i = 2; i <= N; ++i){
		int x, y;
		x = i % 2;
		y = 1 - x;
		for (int j = 1; j <= A; ++j){
			dp[x][0][j] = 0;
			if (j == 1){
				for (int k = 1; k <= B; ++k)
					dp[x][0][j] = (dp[x][0][j]+dp[y][1][k])%1000000007;
			}
			else
				dp[x][0][j] = (dp[x][0][j]+dp[y][0][j - 1]) % 1000000007;
		}
		for (int j = 1; j <= B; ++j){
			dp[x][1][j] = 0;
			if (j == 1){
				for (int k = 1; k <= A; ++k)
					dp[x][1][j] = (dp[x][1][j]+dp[y][0][k]) % 1000000007;
			}
			else
				dp[x][1][j] = (dp[x][1][j]+dp[y][1][j - 1]) % 1000000007;
		}
	}
	int ans = 0;
	for (int i = 1; i <= A; ++i)
		ans = (ans + dp[N % 2][0][i]) % 1000000007;
	for (int i = 1; i <= B; ++i)
		ans = (ans + dp[N % 2][1][i]) % 1000000007;
	cout << ans << endl;
	return 0;
}