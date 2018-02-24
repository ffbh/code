#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;

int main(){
	ifstream in("C:\\input.txt");
	string s;
	map<string, int> msi;
	string pre, now;
	while (getline(cin,s)){
		pre = "";
		if (s == "####"){
			map<string, int>::iterator it = msi.begin();
			int mmax = 0;
			string ans;
			while (it != msi.end()){
				if (it->second > mmax){
					mmax = it->second;
					ans = it->first;
				}
				it++;
			}
			cout << ans << ":" << mmax << endl;
			msi.clear();
		}
		else{
			int a=s.length(), b;
			for (int i = 0; i < s.length();++i)
			if (s[i] >= 'a'&&s[i] <= 'z'){
				a = i;
				break;
			}
			while (a < s.length()){
				b = a;
				while (b<s.length() && s[b] >= 'a'&&s[b] <= 'z')
					b++;
				now = s.substr(a, b - a);
				if (pre.length() != 0){
					msi[pre + " " + now]++;
				}
				pre = now;
				for (a = b; a < s.length(); ++a){
					if (s[a] == ',' || s[a] == '.')
						pre = "";
					else if (s[a] >= 'a'&&s[a] <= 'z')
						break;
				}
			}
		}
	}
	return 0;
}