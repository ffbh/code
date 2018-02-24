#include <iostream>
#include <string>
#include <fstream>
using namespace std;

_int64 dp[100010];
string temp;
int length;
bool clean(string& s){
	int len = s.length();
	for (int i = 0; i < len;++i)
	if (s[i] == '0'){
		if (s[i - 1] == '1' || s[i - 1] == '2'){
			s[i] = s[i - 1] = ' ';
			if (i - 2 >= 0&&(s[i-2]=='1'||s[i-2]=='2'))
				s[i - 2] = '3';
		}
		else return 0;
	}
	return 1;

}

_int64 dfs(int now){
	if (now == length)
		return 1;
	if (dp[now])
		return dp[now];
	if (now < length - 1 && (temp[now] == '1' || temp[now] == '2' && temp[now + 1] <= '6'))
		dp[now] += dfs(now + 2);
	return dp[now] += dfs(now + 1);
}



int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	while (cin >> s&&s != "0"){
		memset(dp, 0, sizeof(dp));
		clean(s);
		temp = "";
		for (int i = 0; i < s.length(); ++i)
		if (s[i] != ' ')
			temp += s[i];
		length = temp.length();
		cout << dfs(0) << endl;
	}
	return 0;
}