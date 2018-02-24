#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
using namespace std;

bool fun(char c){
	return c >= 'A'&&c <= 'Z' || c >= 'a'&&c <= 'z';
}


int main(){
	ifstream in("C:\\temp.txt");
	map<char, char> mcc;
	string s;
	string pre;
	getline(cin, pre);
	set<char> sc(pre.begin(), pre.end());
	for (char c = 'Z'; c >= 'A';--c)
	if (sc.count(c) == 0)
		pre += c;
	string now = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int len = pre.length();
	for (int i = 0; i < len; ++i)
		mcc[pre[i]] = now[i];

	for (int i = 0; i < len; ++i){
		pre[i] += 32;
		now[i] += 32;
	}
	for (int i = 0; i < len; ++i)
		mcc[pre[i]] = now[i];

	
	while (getline(cin, s)){
		int ll = s.length();
		for (int i = 0; i < ll; ++i)
		if (fun(s[i]))
			putchar(mcc[s[i]]);
		else putchar(s[i]);
		putchar('\n');
	}



	return 0;
}