#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
int table[5][5] = {
	5, -1, -2, -1, -3,
	-1, 5, -3, -2, -4,
	-2, -3, 5, -2, -2,
	-1, -2, -2, 5, -1,
	- 3, -4, -2, -1, 0
};

int dp[110][110];
int MAX(int a, int b, int c){
	return max(max(a, b), c);
}

int main(){
	ifstream in("C:\\temp.txt");
	map<char, int> mci;
	mci['A'] = 0;
	mci['C'] = 1;
	mci['G'] = 2;
	mci['T'] = 3;
	int T;
	in >> T;
	while (T--){
		memset(dp, 0, sizeof(dp));
		string s1, s2;
		int t;
		in >> t >> s1;
		in >> t >> s2;
		dp[0][0] = MAX(table[mci[s1[0]]][mci[s2[0]]], table[mci[s1[0]]][4], table[mci[s2[0]]][4]);
		for (int i = 1; i < s1.length(); ++i)
			dp[0][i] = max(table[mci[s1[i]]][4], table[mci[s1[i]]][mci[s2[0]]]);
		for (int i = 1; i < s2.length(); ++i)
			dp[i][0] = max(table[mci[s2[i]]][4], table[mci[s2[i]]][mci[s1[0]]]);
		for (int i = 1; i < s1.length();++i)
		for (int j = 1; j < s2.length();++j)
		if (s1[i] == s2[j])
			dp[i][j] = dp[i - 1][j - 1] + 5;
		else
			dp[i][j] = MAX(dp[i - 1][j - 1] + table[mci[s1[i]]][mci[s2[j]]],
			dp[i][j - 1] + table[s1[i]][4] , dp[i - 1][j] + table[mci[s2[j]]][4]);
		cout << dp[s1.length() - 1][s2.length() - 1] << endl;
	}
	return 0;
}