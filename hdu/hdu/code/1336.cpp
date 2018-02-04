#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
map<string, int> msi;
int cnt;
string s[6];
void dfs(char pre, int n,int k){
	for (char c = pre + 1; c <= 'z'; c++){
		if (k == n){
			s[k][n - 1] = c;
			msi[s[k]] = cnt++;
		}
		else {
			s[k][n - 1] = c;
			dfs(c, n + 1, k);
		}
	}
}

int main(){
	//ifstream in("C:\\temp.txt");
	cnt = 1;
	s[1] = "a";
	s[2] = "ab";
	s[3] = "abc";
	s[4] = "abcd";
	s[5] = "abcde";
	for (int i = 1; i <= 5;++i)
	dfs('a'-1, 1, i);
	string s;
	while (cin >> s){
		cout << msi[s] << endl;
	}
	return 0;
}