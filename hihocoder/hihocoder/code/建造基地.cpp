#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int Q, N, M, K, T;
long long A[110], B[110];
long long dp[10010];
bool judge(){
	for (int i = 1; i <= M;++i)
	if (B[i] > 0)
		return 1;
	return 0;
}


int main(){
	ifstream in("C:\\input.txt");
	cin >> Q;
	while (Q-->0){
		cin >> N >> M >> K >> T;
		for (int i = 1; i <= M; ++i)
			cin >> A[i];
		for (int i = 1; i <= M; ++i)
			cin >> B[i];
		long long ans = 0;
		while (N-- > 0){
			if (!judge()){
				ans = -1;
				break;
			}
			for (int i = 1; i <= K; ++i)
				dp[i] = 1e18;
			dp[0] = 0;
			for (int i = 1; i <= M; ++i){
				for (int j = 1; j < B[i];++j){
					dp[j] = min(dp[j], A[i]);
				}
				for (int j = B[i]; j <= K; ++j){
					if (dp[j] > dp[j - B[i]] + A[i]){
						dp[j] = dp[j - B[i]] + A[i];
					}
				}
				
				
			}
			ans += dp[K];
			for (int i = 1; i <= M; ++i)
				B[i] /= T;
		}
		if (ans != -1)
			cout << ans << endl;
		else
			cout << "No Answer" << endl;


	}
















	return 0;
}