#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;

int data[int(1e5) + 10], N;
long long dp[int(1e5) + 10][32][2];
long long mod = 998244353;
long long mul[int(1e5) + 10];
int getHigh(int p){
	for (int i = 30; i >= 0; --i){

		if (p&(1 << i))
			return i;
	}
	return -1;
}


int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N;
	for (int i = 1; i <= N; ++i)
		in >>  data[i];
	memset(dp, 0, sizeof(dp));
	mul[N] = 1;
	for (int i = N - 1; i > 0; --i)
		mul[i] = mul[i + 1] * 2 % mod;
	for (int i = 0; i < 32; ++i)
		dp[0][i][0] = 1;
	long long ans = 0;
	for (int k = 1; k <= N; ++k){
		int p = getHigh(data[k]);
		if (p != -1){
			ans = (ans + dp[k - 1][p][0] * mul[k] % mod) % mod;
		}
		for (int i = 0; i < 31; ++i){
			if (data[k] & (1 << i)){
				dp[k][i][0] = (dp[k - 1][i][0] + dp[k - 1][i][1]) % mod;
				dp[k][i][1] = (dp[k - 1][i][1] + dp[k - 1][i][0]) % mod;
			}
			else{
				dp[k][i][0] = (dp[k - 1][i][0] + dp[k - 1][i][0]) % mod;
				dp[k][i][1] = (dp[k - 1][i][1] + dp[k - 1][i][1]) % mod;
			}
		}
	}
	cout << ans << endl;

	return 0;
}





