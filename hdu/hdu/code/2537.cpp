#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
double dp[110][110];

int main(){
	ifstream in("C:\\temp.txt");
	int k, n;
	double fenzi, fenmu;
	while (cin >> k >> n){
		fenmu = pow(k + 1.0, n);
		for (int i = 0; i <= k; ++i)
			dp[1][i] = 100.0;
		for (int i = 2; i <= n;++i)
		for (int j = 0; j <= k; ++j){
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
			else if (j == k)
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];
		}
		fenzi = 0;
		for (int i = 0; i <= k; ++i)
			fenzi += dp[n][i];
		printf("%.5f\n", fenzi / fenmu);
	}
	return 0;
}