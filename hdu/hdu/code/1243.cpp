#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
map<char, int> mci;
int dp[2][10010];

int MAX(int a, int b){
	return a > b ? a : b;
}
int MMAX(int a, int b, int c){
	return MAX(MAX(a, b), c);
}

int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		mci.clear();
		memset(dp, 0, sizeof(dp));
		string ss;
		cin >> ss;
		int M = ss.length();
		for (int i = 0; i < N; ++i){
			int t;
			scanf("%d", &t);
		//	in >> t;
			mci[ss[i]] = t;
		}
		string s1, s2;
		cin >> s1 >> s2;
		if (s1[0] == s2[0])
			dp[0][0] = mci[s1[0]];
		for (int i = 1; i < s2.length();++i)
		if (s1[0] == s2[i])
			dp[0][i] = mci[s2[i]];
		else
			dp[0][i] = dp[0][i - 1];
		int K = s1.length();
		int now = 1;
		while (now < K){
			int x, y;
			x = now % 2;
			y = (now + 1) % 2;
			if (s1[now] == s2[0])
				dp[x][0] = mci[s1[now]];
			else
				dp[x][0] = dp[y][0];
			for (int i = 1; i < s2.length(); ++i){
				int c = 0;
				if (s1[now] == s2[i])
					c = mci[s1[now]];
				dp[x][i] = MMAX(c+dp[y][i-1], dp[x][i - 1], dp[y][i]);
			}
			now++;
		}
		cout << dp[(s1.length()+1) % 2][s2.length()-1] << endl;
	}
	return 0;
}