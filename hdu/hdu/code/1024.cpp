#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int M, N;
int data[1000010];
int dp[2][1000100];

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> M >> N){
		int  mmax;
		for (int i = 1; i <= N; ++i)
			cin >> data[i];
		for (int i = 1; i <= N; ++i)
			dp[1][i] = max(dp[1][i - 1] + data[i], data[i]);
		for (int i = 2; i <= M; ++i){
			int x, y;
			x = i % 2;
			y = 1 - x;
			dp[x][i - 1] = mmax = dp[y][i - 1];
			for (int j = i; j <= N; ++j){
				dp[x][j] = max(dp[x][j - 1], mmax) + data[j];
				if (mmax < dp[y][j])
					mmax = dp[y][j];
			}
		}
		mmax = INT_MIN;
		for (int i = M; i <= N;++i)
		if (dp[M % 2][i]>mmax)
			mmax = dp[M % 2][i];
		cout << mmax << endl;
	}



	return 0;
}