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
#include <set>
using namespace std;
long long mod = (long long)1e9 + 7;
long long dp[410], f[410];
int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	dp[1] = 1;
	f[1] = 0;
	f[0] = 0;
	//in >> N;

	for (int i = 2; i < 410; ++i){
		dp[i] = (2 * dp[i - 1] % mod + 1 + 4 * dp[i-1]% mod  + 2 * dp[i - 1] % mod*dp[i - 1] % mod + 4 * f[i-1]%mod) % mod;

		f[i] = (2 * f[i - 1]%mod + dp[i - 1] * dp[i - 1] % mod + 2 * dp[i - 1] % mod + 4 * dp[i - 1] % mod*dp[i - 1] % mod
			+ 6 *  dp[i - 1]%mod * f[i - 1] % mod ) % mod;

	} 


	  

	
	int p = 0;
	p++;

//	cout << dp[N] << endl;















	return 0;
}





