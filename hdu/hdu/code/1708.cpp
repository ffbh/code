#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[52][30];


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	string s1, s2;
	int K;
	while (T--){
		cin >> s1 >> s2 >>  K;
		memset(dp, 0, sizeof(dp));
		int la = s1.length();
		int lb = s2.length();
		for (int i = 0; i < la; ++i)
			dp[0][s1[i] - 'a']++;
		for (int i = 0; i < lb; ++i)
			dp[1][s2[i] - 'a']++;
		for (int i = 2; i <= K;++i)
		for (int j = 0; j < 30; ++j)
			dp[i][j] = dp[i - 1][j] + dp[i - 2][j];

		for (int j = 0; j < 26; ++j)
			printf("%c:%d\n", 'a' + j,  dp[K][j]);
		cout << endl;
	}

	return 0;
}