#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
bool map[30];
int MAX;
string s;
void change(int n){
	if (n == 0){
		 map[0] ^= 1;
		 map[1] ^= 1;
	}
	else if (n == s.length() - 1){
		 map[s.length() - 1] ^= 1;
		 map[s.length() - 2] ^= 1;
	}
	else{
		 map[n] ^= 1;
		 map[n-1] ^= 1;
		 map[n + 1] ^= 1;
	}
}


bool Ok(){
	for (int i = 0; i < s.length();++i)
	if (map[i])
		return 0;
	return 1;
}

void dfs(int n,int cnt){
	if (cnt < MAX&&Ok()){
		MAX = cnt;
		return;
	}
	if (cnt >= MAX||n==s.length())
		return;
	change(n);
	dfs(n + 1,cnt+1);
	change(n);
	dfs(n + 1,cnt);
}


int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> s){
		if (s.length() == 1){
			if (s[0] == '0')
				cout << 0 << endl;
			else
				cout << 1 << endl;
			continue;
		}
		for (int i = 0; i < s.length();++i)
		if (s[i] == '0')
			map[i] = 0;
		else
			map[i] = 1;
		MAX = s.length()+1;
		dfs(0, 0);
		if (MAX == s.length()+1)
			cout << "NO" << endl;
		else
			cout << MAX << endl;
	}
	return 0;
}