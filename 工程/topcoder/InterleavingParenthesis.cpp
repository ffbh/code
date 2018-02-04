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
long long mod = 1e9 + 7;
long long dp[2510][2510];
long long a[2510], b[2510];
int N, M;
class InterleavingParenthesis {
public:
	int countWays(string s1, string s2) {
		N = s1.length();
		M = s2.length();
		s1 = '0' + s1;
		s2 = '0' + s2;
		a[0] = b[0] = 0;
		for (int i = 1; i <= N; ++i){
			if (s1[i] == '('){
				a[i] = a[i - 1] + 1;
			}
			else{
				a[i] = a[i - 1] - 1;
			}
		}

		for (int i = 1; i <= M; ++i){
			if (s2[i] == '('){
				b[i] = b[i - 1] + 1;
			}
			else{
				b[i] = b[i - 1] - 1;
			}
		}

		if (a[N] + b[M] != 0)
			return 0;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 0; i <= N;++i)
		for (int j = 0; j <= M; ++j){
			if (dp[i][j] == 0)
				continue;
			if (i + 1 <= N){
				if (a[i + 1] + b[j] >= 0){
					dp[i + 1][j] += dp[i][j];
					dp[i + 1][j] %= mod;
				}
			}

			if (j + 1 <= M){
				if (a[i] + b[j + 1] >= 0){
					dp[i][j + 1] += dp[i][j];
					dp[i][j + 1] %= mod;
				}
			}
		}
		return (int)dp[N][M];
	}
};


#if 0
int main(){
	





	InterleavingParenthesis so;
	cout<<so.countWays()<<endl;


	return 0;
}
#endif




