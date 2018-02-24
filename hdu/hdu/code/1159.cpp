#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int dp[2][510];
char s1[510], s2[510];

int main(){
	ifstream in("C:\\temp.txt");
	s1[0] = s2[0] = 1;
	while (cin >> s1+1 >> s2+1){
		int x, y;
		int len1 = strlen(s1 + 1);
		int len2 = strlen(s2 + 1);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <=len1;++i)
		for (int j = 1; j <= len2; ++j){
			x = i % 2;
			y = 1 - x;
			if (s1[i] == s2[j]){
				
					dp[x][j] = dp[y][j - 1] + 1;
			}
			else{
				
					dp[x][j] = max(dp[y][j],dp[x][j-1]);
			}
		}
		cout << dp[(len1) % 2][len2] << endl;


	}



	return 0;
}