#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int N, M;
int dp[21][21];
bool map[21][21];
int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M&&N+M){
		memset(map, 0, sizeof(map));
		while (M--){
			int a, b;
			cin >> a >> b;
			map[b][a] = 1;
		}
		cin >> M;
		while (M--){
			int a, b, c;
			cin >> a >> b >> c;
			memset(dp, 0, sizeof(dp));
			dp[0][a] = 1;
			for (int i = 1; i <= c; ++i)
			for (int j = 0; j < N; ++j){
				for (int k = 0; k < N; ++k)
				if (map[j][k] && j != k)
					dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 1000;
			}
			cout << dp[c][b] << endl;
		}
	}
	return 0;
}