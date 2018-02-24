#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int dp[110][110];
int data[110][110];


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= i; ++j)
			cin >> data[i][j];
		dp[1][1] = data[1][1];
		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j){
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + data[i + 1][j]);
			dp[i + 1][j+1] = max(dp[i + 1][j+1], dp[i][j] + data[i + 1][j+1]);
		}
		int mmax = 0;
		for (int i = 1; i <= N;++i)
		if (dp[N][i] > mmax)
			mmax = dp[N][i];
		cout << mmax << endl;
	}







	return 0;
}