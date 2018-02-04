#include <iostream>
#include <algorithm>
//#include <fstream>
using namespace std;
int N;
int num[101][101];
int dp[101][101];
int fun(int x, int y){
	memset(dp, 0,sizeof(dp));
	dp[x][y] = num[x][y];
	for (int i = y+1; i < N; ++i)
		dp[x][i] = dp[x][i-1]+num[x][i];
	for (int i = x+1; i < N; ++i)
		dp[i][y] = dp[i-1][y]+num[i][y];
	for (int i = x+1; i < N;++i)
	for (int j = y+1; j < N;++j)
		dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]+num[i][j];
	int mmax = INT_MIN;
	for (int i = x; i < N; ++i)
	for (int j = y; j < N; ++j)
		mmax = max(mmax, dp[i][j]);
	return mmax;
}
int main(){
	//ifstream in("C:\\temp.txt");
	//while (scanf("%d", &N) != EOF){
	while (cin>>N){
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j)
			scanf("%d", &num[i][j]);
		//	in >> num[i][j];
		int mmax=INT_MIN;
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			mmax = max(mmax, fun(i, j));
		if (mmax < 0)mmax = 0;//如果矩阵全部为负数，则输出0
		cout << mmax << endl;

		

	}


	return 0;
}