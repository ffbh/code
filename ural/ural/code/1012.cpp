#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[1810][2];

int main(){
	ifstream in("C:\\temp.txt");
	int N, K;
	while (cin >> N >> K){
		memset(dp, 0, sizeof(dp));
		dp[1][0] = 1;
		dp[1][1] = K - 1;
		for (int i = 2; i <= N; ++i){
			dp[i][0] = dp[i - 1][1];
			dp[i][1] = (dp[i - 1][0] + dp[i - 1][1])*(K - 1);
		}
		cout << dp[N][1] << endl;


	}






	return 0;
}