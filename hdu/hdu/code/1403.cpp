#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

char s1[100010], s2[100010];
int dp[2][100010];


int main(){
	ifstream in("C:\\input.txt");
	while (cin >> (s1 + 1) >> (s2 + 1)){
		int len1 = strlen(s1 + 1);
		int len2 = strlen(s2 + 1);
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for (int i = 1; i <= len1;++i)
		for (int j = 1; j <= len2; ++j){
			int f = i % 2;
			int pf = 1 - f;
			if (s1[i] == s2[j]){
				dp[f][j] = dp[pf][j - 1] + 1;
			}
			else
				dp[f][j] = 0;
			ans = max(ans, dp[f][j]);
		}
		cout << ans << endl;


	}


	return 0;
}