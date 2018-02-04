#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
const long long mod = 1000000007;
long long C[2010][2010];
long long dp[2010][2010];

long long qm(long long a, int p){
	long long ret = 1;
	while (p){
		if (p & 1)
			ret = (ret*a) % mod;
		a = (a*a) % mod;
		p /= 2;
	}
	return ret;
}

void Init(){
	for (int i = 1; i < 2010; ++i){
		C[i][0] = C[i][i] = 1;
	}
	for (int i = 2; i < 2010;++i)
	for (int j = 1; j <= i; ++j)
		C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%mod;

	dp[2][1] = dp[2][2] = 1;
	for (int i = 3; i < 150; ++i){
		dp[i][1] = qm(i, i - 2);
		for (int j = 2; j <= i;++j){
			for (int k = 0; k < i-j;++k)
				dp[i][j] = (dp[i][j] + C[i - j][k]*dp[i - k - 1][j - 1] * dp[k + 1][1]) % mod;
		}
	}


}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	int T;
	in >> T;
	while (T-- > 0){
		int n, s;
		in >> n >> s;
		cout << dp[n][s] << endl;

	}
















	return 0;
}