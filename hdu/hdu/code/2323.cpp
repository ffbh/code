#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[15][50][50];
void Init(){
	dp[0][15][15] = 1;
	for (int k = 0; k < 15;++k)
	for (int i = 1; i < 31;++i)
	for (int j = 1; j < 31;++j)
	if (dp[k][i][j]){
		dp[k + 1][i][j + 1] += dp[k][i][j];
		dp[k + 1][i][j - 1] += dp[k][i][j];
		dp[k + 1][i + 1][j] += dp[k][i][j];
		dp[k + 1][i - 1][j] += dp[k][i][j];
		dp[k + 1][i + 1][j + 1] += dp[k][i][j];
		dp[k + 1][i - 1][j - 1] += dp[k][i][j];
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	ofstream on("C:\\temp2.txt");
	//Init();
	int data[] = { 0, 0, 6, 12, 90, 360, 2040, 10080, 54810, 290640, 1588356, 8676360, 47977776, 266378112, 1488801600 };
	int T;
	scanf("%d", &T);
	while (T--){
		int N;
		scanf("%d", &N);
		printf("%d\n", data[N]);
	}
/*	for (int i = 1; i <= 14; ++i)
		on << dp[i][15][15] << ",";*/
	return 0;
}