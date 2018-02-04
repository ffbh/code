#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;

string s;
int dp[110][110];
int main(){
	ifstream in("C:\\temp.txt");

	while (getline(cin, s) && s != "end"){
		for (int i = 0; i<s.length(); ++i){
			dp[i][i] = 0;

		}
		for (int len = 2; len <= s.length(); ++len)
		for (int i = 0; i + len <= s.length(); ++i){
			int j = i + len - 1;
			if (s[i] == '('&&s[j] == ')' || s[i] == '['&&s[j] == ']')
				dp[i][j] = dp[i + 1][j - 1] + 2;
			else
				dp[i][j] = 0;
			for (int k = i; k<j; ++k)
			if (dp[i][j]<dp[i][k] + dp[k + 1][j])
				dp[i][j] = dp[i][k] + dp[k + 1][j];


		}




		cout << dp[0][s.length() - 1] << endl;
	}
	return 0;
}