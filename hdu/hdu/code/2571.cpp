#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define INF (-888888888)
int data[25][1010];
int dp[25][1010];
int N, M;
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >>  M;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j){
			cin >> data[i][j];
			dp[i][j] = INF;
		}
		dp[1][1] = data[1][1];
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j){
			if (dp[i + 1][j] < dp[i][j] + data[i + 1][j])
				dp[i + 1][j] = dp[i][j] + data[i + 1][j];
			if (dp[i][j + 1] < dp[i][j] + data[i][j + 1])
				dp[i][j + 1] = dp[i][j] + data[i][j + 1];
			for (int k = 2; k*j <= M;++k)
			if (dp[i][k*j] < dp[i][j] + data[i][k*j])
				dp[i][k*j] = dp[i][j] + data[i][k*j];
		}
		cout << dp[N][M] << endl;





	}



	return 0;
}