#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int dp[110][110];
int mark[110][110];
string s;
void Print(int i, int j){
	if (i > j)
		return;
	if (i == j){
		if (s[i] == '(' || s[i] == ')')
			printf("()");
		else
			printf("[]");
		return;
	}
	if (mark[i][j] == -1){
		putchar(s[i]);
		Print(i + 1, j - 1);
		putchar(s[j]);
	}
	else{
		Print(i, mark[i][j]);
		Print(mark[i][j] + 1, j);
	}
}



int main(){
	ifstream in("C:\\temp.txt");
	getline(cin, s);
	for (int i = 0; i < s.length(); ++i){
		dp[i][i - 1] = 0;
		dp[i][i] = 1;
	}
	for (int len = 2; len <= s.length();++len)
	for (int i = 0; i + len - 1 < s.length(); ++i){
		int j = i + len - 1;
		dp[i][j] = 9999999;
		if (s[i] == '(' && s[j] == ')' || s[i] == '['&&s[j] == ']'){
			dp[i][j] = dp[i + 1][j - 1];
			mark[i][j] = -1;
		}
		for (int k = i; k<j; ++k)
		if (dp[i][j] > dp[i][k] + dp[k + 1][j]){
			dp[i][j] = dp[i][k] + dp[k + 1][j];
			mark[i][j] = k;
		}
	}
	Print(0, s.length() - 1);
	cout << endl;
	return 0;
}