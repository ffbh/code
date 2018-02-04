#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
long long dp[1010][1010], p[1010];
long long mod = 1000000007;

int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	
	p[1] = 1;
	for (int i = 2; i <= N; ++i){
		p[i] = (p[i - 1] * i) % mod;
	}
	dp[1][1] = 1;
	for (int i = 2; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			dp[i][j] = (j*dp[i - 1][j] + dp[i - 1][j - 1])%mod;
	

		long long ans = 0;
		for (int i = 1; i <= N; ++i)
			ans = (ans + dp[N][i] * p[i]) % mod;
		cout << ans << endl;

	return 0;
}