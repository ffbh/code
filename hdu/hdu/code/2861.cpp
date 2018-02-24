#include <iostream>
#include <string>
#include <fstream>
using namespace std;
unsigned _int64 dp[22][210][210][2];

int main(){
	ifstream in("C:\\temp.txt");
	int N, M, K;
	dp[1][1][0][0] = 1;
	dp[1][1][1][1] = 1;
	for (int k = 1; k <= 20; ++k)
	for (int i = 1; i <= 200; ++i){
		dp[1][i][0][0] = 1;
		for (int j = 1; j <= i; ++j){
			if (k == 1 && i == 1 && (j == 0 || j == 1))
				continue;
			dp[k][i][j][0] = dp[k][i - 1][j][0] + dp[k - 1][i - 1][j][1];
			dp[k][i][j][1] = dp[k][i - 1][j - 1][1] + dp[k - 1][i - 1][j - 1][0];
		}
	}
	while (~scanf("%d%d%d", &N, &M, &K))
		printf("%I64d\n", dp[K][N][M][0] + dp[K][N][M][1]);
	



	return 0;
}