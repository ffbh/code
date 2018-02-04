#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int T, N;
int dp[50010];
int h[510], c[510];
long long cale(long long a, long long b){
	return a*a - a*b - b*b;
}



int main(){
	ifstream in("C:\\input.txt");
	cin >> T;
	while (T-- > 0){
		memset(dp, -1, sizeof(dp));
		cin >> N;
		int sum = 0;
		for (int i = 1; i <= N; ++i){
			cin >> h[i] >> c[i];
			sum += c[i];
		}
		dp[0] = 0;
		for (int k = 1; k <= N; ++k){
			for (int i = sum; i >= c[k]; --i){
				if (dp[i - c[k]] != -1 && dp[i] < dp[i-c[k]] + h[k]) {
					dp[i] = dp[i - c[k]] + h[k];
				}
			}
		}

		long long ans = 0;
		for (int i = 0; i <= sum; ++i){
			if (i == 2){
				int t = 0;
			}
			if (dp[i] != -1){
				long long ret = cale(dp[i], i);
				if (ans < ret)
					ans = ret;
			}

		}

		
		cout << ans << endl;

	}

	return 0;
}