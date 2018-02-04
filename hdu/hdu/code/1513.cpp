#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[2][5010];
int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		memset(dp, 0, sizeof(dp));
		string s;
		cin >> s;
		string ts(s.rbegin(), s.rend());
		int len = s.length();
		if (s[0] == ts[0])
			dp[0][0] = 1;
		for (int i = 1; i < len; ++i)
		if (s[0] == ts[i])
			dp[0][i] = 1;
		else
			dp[0][i] = dp[0][i - 1];
		int now = 1;
		while (now < len){
			int x, y;
			x = now % 2;
			y = (now + 1) % 2;
			if (s[now] == ts[0])
				dp[x][0] = 1;
			else
				dp[x][0] = dp[y][0];
			for (int i = 1; i < len; ++i)
			if (s[now] == ts[i])
				dp[x][i] = dp[y][i - 1] + 1;
			else
				dp[x][i] = max(dp[x][i - 1], dp[y][i]);
			now++;
		}
		cout << len - dp[(len + 1) % 2][len - 1] << endl;
	}
	return 0;
}