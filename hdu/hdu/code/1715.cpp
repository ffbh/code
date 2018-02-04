#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MMAX = 10000000;
int dp[1010][500];


int main(){
//	ifstream in("C:\\temp.txt");
	dp[1][0] = dp[2][0] = 1;
	dp[1][1] = dp[2][1] = 1;
	for (int i = 3; i < 1010; ++i){
		dp[i][0] = dp[i - 1][0];
		for (int j = 1; j <= dp[i][0]; ++j){
			dp[i][j] += dp[i - 1][j] + dp[i - 2][j];
			if (dp[i][j] >= MMAX){
				dp[i][j] -= MMAX;
				dp[i][j + 1] = 1;
			}
			if (dp[i][dp[i][0] + 1])
				dp[i][0]++;
		}
	}
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		int len = dp[N][0];
		cout << dp[N][len];
		for (int i = len - 1; i >= 1; --i)
			printf("%07d", dp[N][i]);
		cout << endl;


	}
	return 0;
	
}