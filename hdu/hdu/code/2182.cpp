#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[101];
int data[101];
bool vis[101];
int main(){
	ifstream in("C:\\temp.txt");
	int N, A, B, K;
	int T;
	cin >> T;
	while (T--){
		cin >> N >> A >> B >> K;
		for (int i = 0; i < N; ++i)
			cin >> data[i];
		memset(dp, -1, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		dp[0] = data[0];
		vis[0] = 1;
		while (K--)
		for (int j = 0; j < N; ++j)
		for (int k = A; k <= B; ++k){
			if (j - k >= 0 && vis[j - k]){
				vis[j] = 1;
				if (dp[j] < dp[j - k] + data[j])
					dp[j] = dp[j - k] + data[j];
			}
		}
		int mmax = 0;
		for (int i = 0; i < N; ++i)
		if (dp[i]>mmax&&vis[i])
			mmax = dp[i];
		cout << mmax << endl;
	}
	return 0;
}