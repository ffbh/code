#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[110][110];

int main(){
	ifstream in("C:\\temp.txt");
	int N, P, M, T;
	while (cin >> N >> P >> M >> T){
		memset(dp, 0, sizeof(dp));
		dp[0][P] = 1;
		for (int i = 1; i <= M;++i)
		for (int j = 1; j <= N; ++j)
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
		cout << dp[M][T] << endl;
	}



	return 0;
}