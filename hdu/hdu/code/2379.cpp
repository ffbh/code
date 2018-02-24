#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int num[15];
_int64 dp[6][100];
int main(){
	ifstream in("C:\\temp.txt");
	int m, n, q;
	int T;
	cin >> T;
	while (T--){
		cin >> m >> n >> q;
		memset(num, 0, sizeof(num));
		memset(dp, 0, sizeof(dp));
		while (m--){
			string t;
			cin >> t;
			num[t.length()]++;
		}
		for (int i = 0; i < 15; ++i)
			dp[1][i] = num[i];
		for (int i = 2; i <=n;++i)
		for (int j = 0; j < 100;++j)
		for (int k = 1; k < 15; ++k)
			dp[i][j] += dp[i - 1][j - k] * num[k];
		while (q--){
			int t;
			cin >> t;
			cout << dp[n][t] << endl;
		}
	}
	return 0;
}