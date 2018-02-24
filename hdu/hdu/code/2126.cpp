#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[31][510];

int main(){
	ifstream in("C:\\temp.txt");
	int T, N, M;
	cin >> T;
	while (T--){
		cin >> N >> M;
		int D = N;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		while(N--){
			int t;
			cin >> t;
			for (int i = D; i >= 1;--i)
			for (int j = M; j >= t; --j)
				dp[i][j] += dp[i - 1][j - t];
		}
		int ans = 0;
		int num = 0;
		for (int i = D; i >= 0; --i){
			for (int j = M; j >= 0; --j)
			if (dp[i][j]){
				ans += dp[i][j];
			}
			if (ans){
				num = i;
				break;
			}
		}
		if (num == 0)
			printf("Sorry, you can't buy anything.\n");
		else
			printf("You have %d selection(s) to buy with %d kind(s) of souvenirs.\n", ans, num);
			
	}






	return 0;
}