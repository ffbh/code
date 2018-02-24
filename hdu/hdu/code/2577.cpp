#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int dp[2][110];

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	string s;
	cin >> T;
	while (T--){
		cin >> s;
		s = '0' + s;
		dp[0][0] = 0;
		dp[1][0] = 1;
		for (int i = 1; i < s.length();++i)
		for (int j = 0; j < 2; ++j){
			if (s[i] >= 'a'&&s[i] <= 'z'){
				dp[0][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] + 2);
				dp[1][i] = min(dp[1][i-1] , dp[0][i-1] )+2;
			}
			else {
				dp[0][i] = min(dp[1][i - 1], dp[0][i - 1]) + 2;
				dp[1][i] = min(dp[1][i - 1] + 1, dp[0][i - 1] + 2);
			}
		}
		cout << min(dp[0][s.length() - 1], dp[1][s.length() - 1] + 1) << endl;
	}
	return 0;
}