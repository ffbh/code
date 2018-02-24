#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int data[110][110];
int dp[210][110][110];
int mmax(int a, int b, int c, int d){
	return max(max(a, b), max(c,d));
}

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin>>N){
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j)
			cin >> data[i][j];
		int c = 0;
		dp[0][0][0] = data[0][0];
		for (int k = 1; k <= 2*N-2;++k)/////////
		for (int i = 0; i < N;++i)
		for (int j = i; j < N; ++j)
		if (k >= i&&k >= j){
			if (i!=j)
			dp[k][i][j] = mmax(dp[k - 1][i][j], dp[k - 1][i][j - 1], dp[k - 1][i - 1][j], dp[k - 1][i - 1][j - 1])
				+ data[k - i][i] + data[k - j][j];
			else 
				dp[k][i][j] = mmax(dp[k - 1][i][j], dp[k - 1][i][j - 1], dp[k - 1][i - 1][j], dp[k - 1][i - 1][j - 1])
				+ data[k - i][i];
		}
		int b = 0;
		cout << dp[2 * N - 2][N - 1][N - 1] << endl;
	}
	return 0;
}