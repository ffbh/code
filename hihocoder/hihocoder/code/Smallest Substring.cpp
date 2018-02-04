#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <stack>
using namespace std;
string ans;
int main(){
	ifstream in("C:\\input.txt");
	int K;
	string s;
	cin >> K >> s;
	ans = "";
	int del = s.length() - K;
	for (int i = 0; i < s.length(); ++i){
		while (ans.length()!= 0 && ans.back() > s[i] && del){
			ans.pop_back();
			del--;
		}
		ans.push_back(s[i]);
	}
	cout << ans.substr(0,K) << endl;
	return 0;
}