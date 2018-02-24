#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[110][110];

int main(){
	ifstream in("C:\\temp.txt");
	int n, m, k, s;
	while (cin >> n >> m >> k >> s){
		memset(dp, 0, sizeof(dp));
		while (k--){
			int a, b;
			cin >> a >> b;
			for (int i = 1; i <= s;++i)
			for (int j = b; j <= m;++j)
			if (dp[i][j] < dp[i - 1][j - b] + a)
				dp[i][j] = dp[i - 1][j - b] + a;
		}
		int ans = -1;
		for (int i = 0; i <= m;++i)
		if (dp[s][i] >= n){
			ans = m - i;
			break;
		}
		cout << ans << endl;





	}



	return 0;
}