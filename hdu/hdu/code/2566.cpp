#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int data[] = { 1, 2, 5 };
int dp[1010][1010];
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int N, M;
		cin >> N >> M;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int k = 0; k < 3;++k)
		for (int i = 1; i <= N;++i)
		for (int j = 0; j <= M;++j)
		if (j - data[k] >= 0)
			dp[i][j] += dp[i - 1][j - data[k]];
		int c;
		cout << dp[N][M] << endl;



	}








	return 0;
}