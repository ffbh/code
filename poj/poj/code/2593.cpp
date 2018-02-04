#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int N;
int data[100010];
int dp[3][100010];

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N&&N){
		for (int i = 1; i <= N; ++i)
			cin >> data[i];
		for (int i = 1; i <= N; ++i)
			dp[1][i] = max(dp[1][i - 1] + data[i], data[i]);
		int mmax = dp[1][1];
		int ans = -999999999;
		dp[2][1] = dp[1][1];
		for (int i = 2; i <= N; ++i){
			dp[2][i] = max(dp[2][i - 1],mmax) + data[i];
			if (ans < dp[2][i])
				ans = dp[2][i];
			if (mmax < dp[1][i])
				mmax = dp[1][i];
		}
		cout << ans << endl;

	}



	return 0;
}