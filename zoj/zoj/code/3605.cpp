#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M, K, S;
struct Node{
	int a, b;
}data[120];
long long dp[60][60][60];

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> N >> M >> K >> S;
		for (int i = 1; i <= M; ++i)
			cin >> data[i].a >> data[i].b;
		memset(dp, 0, sizeof(dp));
		dp[0][0][S] = 1;
		for (int i = 1; i <= M; ++i)
		for (int j = 0; j <= i; ++j){
			for (int k = 1; k <= N; ++k)
				dp[i][j][k] += dp[i - 1][j][k];
			if (j > 0){
				dp[i][j][data[i].a] += dp[i - 1][j - 1][data[i].b];
				dp[i][j][data[i].b] += dp[i - 1][j - 1][data[i].a];
				for (int k = 1; k <= N; ++k)
				if (k != data[i].a&&k != data[i].b)
					dp[i][j][k] += dp[i - 1][j - 1][k];
			}
		}
		
		int mmax = 1;
		for (int i = 2; i <= N; ++i)
		if (dp[M][K][i] > dp[M][K][mmax])
			mmax = i;
		cout << mmax << endl;
	}
	return 0;
}