/*#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
char str[110];
int dp[2][110];
int N;
bool cmp(string& a, string& b){
	if (a.length() != b.length())
		return a.length()<b.length();
	return a <= b;
}

int dfs(int pos, bool flag, string& pre){
	if (pos == N){
		return dp[flag][pos] = 0;
	}
	if (dp[flag][pos] != -1)
		return dp[flag][pos];
	string data = "";
	for (int i = pos; i<N; ++i){
		if (data.length() || str[i] != '0')
			data += str[i];
		if (flag&&cmp(pre, data) || !flag&&cmp(data, pre))
			continue;
		int tmp = dfs(i + 1, !flag, data);
		if (tmp != -1 && dp[flag][pos]<tmp + 1)
			dp[flag][pos] = tmp + 1;
	}
	return dp[flag][pos];
}


int main(){
	ifstream in("C:\\temp.txt");

	while (in >> N){
		in >> str;
		string max(210, '1');
		memset(dp, -1, sizeof(dp));
		int mmax = dfs(0, 1, max) - 1;
		cout << mmax << endl;
	}






	return 0;
}*/