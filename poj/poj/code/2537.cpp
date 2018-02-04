#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;
double dp[110][11];

int main(){
	ifstream in("C:\\input.txt");
	int k, n;
	while (cin >> k >> n){
		memset(dp, 0, sizeof(dp));
		double sum = pow((double)k + 1, (double)n);
		for (int i = 0; i <= k;++i)
			dp[1][i] = 1;
		for (int i = 2; i <= n;++i)
		for (int j = 0; j <= k; ++j){
			if (j > 0)
				dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] += dp[i - 1][j];
			if (j < k)
				dp[i][j] += dp[i - 1][j + 1];
		}
		double ll = 0;
		for (int i = 0; i <= k; ++i)
			ll += dp[n][i];
		printf("%.5f\n", 100 * ll / sum);


	}
	return 0;
}