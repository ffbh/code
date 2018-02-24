#include <iostream>
#include <string>
#include <fstream>
using namespace std;
double data[4][4];
double dp[1010][4];
int a, b, day;
void DP(){
	memset(dp, 0, sizeof(dp));
	dp[0][a] = 1;
	for (int k = 1; k <= day;++k)
	for (int i = 1; i <= 3;++i)
	for (int j = 1; j <= 3; ++j)
		dp[k][i] += dp[k - 1][j] * data[j][i];
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		for (int i = 1; i <= 3;++i)
		for (int j = 1; j <= 3; ++j)
			//cin >> data[i][j];
			scanf("%lf", &data[i][j]);
		int M;
		cin >> M;
		while (M--){
			//cin >> a >> b >> day;
			scanf("%d%d%d", &a, &b, &day);
			DP();
			printf("%.3f\n", dp[day][b]);
		}
	}
	return 0;
}