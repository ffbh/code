#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
const unsigned int mod = 1000000007;
unsigned int dp[110][200010];
int N, S, mmin, mmax;

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> S;
	mmin = mmax = 100000;
	dp[0][100000] = 1;
	for (int i = 1; i <= N; ++i){
		int v;
		cin >> v;
		for (int j = mmin; j <= mmax; ++j){
			if (dp[i - 1][j]){
				dp[i][j + v] = (dp[i][j + v] + dp[i - 1][j]) %mod;
				dp[i][j - v] = (dp[i][j - v] + dp[i - 1][j]) %mod;
			}
		}
		mmin -= v;
		mmax += v;
	}
	cout << dp[N][S + 100000] << endl;
	return 0;
}