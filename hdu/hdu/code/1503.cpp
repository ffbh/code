#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int dp[110][110];
int mark[110][110];
string s1, s2;

void Print(int i, int j){
	if (!i &&!j)
		return;
	if (mark[i][j] == 0){
		Print(i - 1, j - 1);
		putchar(s1[i - 1]);
	}
	else if (mark[i][j] == 1){
		Print(i - 1, j);
		putchar(s1[i - 1]);
	}
	else{
		Print(i, j - 1);
		putchar(s2[j - 1]);
	}

}

int main(){
	ifstream in("C:\\temp.txt");
	
	int len1, len2;
	while (cin >> s1 >> s2){
		memset(dp, 0, sizeof(dp));
		len1 = s1.length();
		len2 = s2.length();
		for (int i = 0; i < 110; ++i){
			dp[i][0] = dp[0][i] = 0;
			mark[0][i] = -1;
			mark[i][0] = 1;
		}
		for (int i = 1; i <= len1;++i)
		for (int j = 1; j <= len2;++j)
		if (s1[i - 1] == s2[j - 1]){
			dp[i][j] = dp[i - 1][j - 1] + 1;
			mark[i][j] = 0;
		}
		else if (dp[i - 1][j] >= dp[i][j - 1]){
			dp[i][j] = dp[i - 1][j];
			mark[i][j] = 1;
		}
		else{
			dp[i][j] = dp[i][j - 1];
			mark[i][j] = -1;
		}



		Print(len1, len2);

		putchar('\n');
	}

	return 0;
}






