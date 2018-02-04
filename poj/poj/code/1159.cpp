#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int dp[2][5010];
char s1[5010], s2[5010];
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		memset(dp, 0, sizeof(dp));
		cin >> (s1+1);
		int len = strlen(s1 + 1);
		for (int i = len; i >= 1; --i)
			s2[i] = s1[len - i+1];
		for (int i = 1; i <= len;++i)
		for (int j = 1; j <= len; ++j){
			int x, y;
			x = i % 2;
			y = 1 - x;
			if (s1[i] == s2[j])
				dp[x][j] = dp[y][j-1] + 1;
			else
				dp[x][j] = max(dp[x][j - 1], dp[y][j]);
		}
		cout << len - dp[len % 2][len] << endl;
	}
	return 0;
}