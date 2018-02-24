#include <iostream>
#include <string>
#include <fstream>
using namespace std;
_int64 dp[55][55];

int main(){
	ifstream in("C:\\temp.txt");
	dp[0][0] = 1;
	for (int i = 1; i <= 50; ++i)
	for (int j = 0; j <= 50; ++j){
		if (j == 0)
			dp[i][j] = dp[i - 1][j] * 2;
		else
			dp[i][j] = 2 * dp[i - 1][j] + dp[i - 1][j - 1];
	}
	int x, y;
	while (in >> x >> y){
		_int64 sum1, sum2;
		sum2 = 0;
		for (int i = 0; i <= y; ++i)
			sum2 += dp[x][i];
		sum1 = sum2 - dp[x][0];
		printf("%.5f\n", double(sum1*100) / (sum2));

	}



	return 0;
}