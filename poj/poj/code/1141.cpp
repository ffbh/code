#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
#define INF (1<<29)
int dp[110][110];
int mark[110][110];

string s;

void print(int l, int r){
	if (l > r)
		return;
	if (l == r){
		if (s[l] == '(' || s[l] == ')')
			cout << "()";
		else
			cout << "[]";
		return;
	}
	if (mark[l][r] == -1){
		putchar(s[l]);
		print(l + 1, r - 1);
		putchar(s[r]);
	}
	else{
		print(l, mark[l][r]);
		print(mark[l][r] + 1, r);
	}
}




int main(){
	ifstream in("C:\\temp.txt");
	while (getline(cin,s)){
		for (int i = 0; i < s.length(); ++i){
			dp[i][i] = 1;
		}
		for (int len = 2; len <= s.length();++len)
		for (int i = 0; i + len - 1 < s.length(); ++i){
			int j = i + len - 1;
			dp[i][j] = INF;
			if (s[i] == '('&&s[j] == ')' || s[i] == '['&&s[j] == ']'){
				dp[i][j] = dp[i + 1][j - 1];
				mark[i][j] = -1;
			}
			for (int k = i; k < j; ++k)
			if (dp[i][j] > dp[i][k] + dp[k + 1][j]){
				dp[i][j] = dp[i][k] + dp[k + 1][j];
				mark[i][j] = k;
			}
		}
		print(0, s.length() - 1); 
		cout << endl;

	}

	return 0;
}