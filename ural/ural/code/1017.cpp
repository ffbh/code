#include <iostream>
#include <string>
#include <fstream>
using namespace std;
long long dp[510][510];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i <= N; ++i)
		for (int j = 0; j <= N; ++j)
		if (dp[i][j]){
			for (int k = j + 1; k <= (N - i); ++k)
				dp[i + k][k] += dp[i][j];
		}
		long long sum = 0;
		for (int i = 0; i <= N; ++i)
			sum += dp[N][i];
		cout << sum - 1 << endl;
	}
	return 0;
}