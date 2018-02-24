#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
char ans[30];
int dex;
bool vis[30];
int main(){
	ifstream in("C:\\input.txt");
	string s;
	cin >> s;
	dex = 1;
	for (int i = 0; i < s.length(); ++i){
		if (s[i] == 'J')
			s[i] = 'I';
		if (vis[s[i] - 'A'])
			continue;
		vis[s[i] - 'A'] = 1;
		ans[dex++] = s[i];
	}
	for (char c = 'A'; c <= 'Z'; ++c){
		if (c == 'J')
			continue;
		if (vis[c - 'A'])
			continue;
		vis[c - 'A'] = 1;
		ans[dex++] = c;
	}
	for (int i = 1; i <= 25; ++i){
		putchar(ans[i]);
		if (i % 5 == 0)
			cout << endl;
	}














	return 0;
}