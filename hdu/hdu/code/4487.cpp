#include <iostream>
#include <string>
#include <fstream>
using namespace std;
double dp[110][220];

int main(){
	ifstream in("C:\\temp.txt");
	int T, CASE, step;
	double l, r;
	in >> T;
	while (T--){
		in >> CASE >> step >> l >> r;
		double m = 1.0 - l - r;
		memset(dp, 0, sizeof(dp));
		dp[0][105] = 1;
		for (int i = 0; i <= step;++i)
		for (int j = 0; j < 220;++j)
		if (dp[i][j]){
			dp[i + 1][j] += dp[i][j] * m;
			dp[i + 1][j + 1] += dp[i][j] * r;
			dp[i + 1][j - 1] += dp[i][j] * l;
		}
		int a;
		double ans = 0;
		for (int i = 1; i <= step;++i)
		for (int j = 220; j >105; --j)
		if(dp[i][j]){
			ans += dp[i][j];
			break;
		}
		printf("%d %.4f\n", CASE, ans);

	}









	return 0;
}