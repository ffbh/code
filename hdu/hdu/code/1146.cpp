#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N;
int dp[110][110];
int data[110][110];
int fun(int x, int y){
	int ret = dp[x][y] = data[x][y];
	for (int j = y + 1; j <= N; ++j){
		dp[x][j] = dp[x][j - 1] + data[x][j];
		if (dp[x][j] > ret)
			ret = dp[x][j];
	}
	for (int i = x + 1; i <= N; ++i){
		dp[i][y] = dp[i - 1][y] + data[i][y];
		if (dp[i][y] > ret)
			ret = dp[i][y];
	}
	for (int i = x + 1; i <= N;++i)
	for (int j = y + 1; j <= N; ++j){
		dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + data[i][j];
		if (dp[i][j] > ret)
			ret = dp[i][j];
	}
	return ret;
}



int main(){
	ifstream in("C:\\temp.txt");
	
	while (cin >> N){
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j)
			//in >> data[i][j];
			scanf("%d", &data[i][j]);
		int mmax = INT_MIN;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j){
			int tmp = fun(i, j);
			if (tmp > mmax)
				mmax = tmp;

		}
		cout << mmax << endl;
	}
	return 0;
}