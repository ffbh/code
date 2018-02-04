#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <set>
using namespace std;
bool fb[30], vis[30];
void InitFB(){
	int f[222];
	f[0] = f[1] = 1;
	fb[1] = 1;
	for (int i = 2; f[i - 1] < 30; ++i)
		fb[f[i] = f[i - 1] + f[i - 2]] = 1;
}




int main(){
	ifstream in("C:\\input.txt");
	string s;
	set<string> si;
	InitFB();
	while (cin >> s){
		si.clear();
		for (int i = 0; i < s.length(); ++i){
			memset(vis, 0, sizeof(vis));
			int num = 0;
			for (int j = i; j < s.length(); ++j){
				if (!vis[s[j] - 'a']){
					vis[s[j] - 'a'] = 1;
					num++;
				}
				if (fb[num]){
					si.insert(s.substr(i, j - i + 1));
				}
			}
		}
		set<string>::iterator it = si.begin();
		while (it != si.end()){
			printf("%s\n", (*it).c_str());
			it++;
		}
	}
	return 0;
}