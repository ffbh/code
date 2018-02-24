#include <iostream>
#include <string>
using namespace std;
string add( string& s1,  string& s2){
	int len1 = s1.length();
	int len2 = s2.length();
	for (int i = 0; i < len1; ++i) s1[i] -= '0'; 
	for (int i = 0; i < len2; ++i) s2[i] -= '0';
	int i, j;
	string t=s1;
	for (i = len2 - 1, j = len1 - 1; i >= 0; --i, --j)
		t[j] += s2[i];
	int flag = 0;
	for (int k = len1 - 1; k >= 0; --k){
		t[k] += flag;
		flag = t[k] / 10;
		t[k] %= 10;
	}
	for (int i = 0; i < len1; ++i) t[i] += '0';
	if (flag)
		t = char(flag+'0') + t;
	return t;
}

int main(){
	int n;
	cin >> n;
	while (n-- > 0){
		string s1, s2;
		cin >> s1;
		if (s1 == "0"){//第一个数为0直接输出零
			cout << 0 << endl;
			goto stop;
		}
		while (cin >> s2&&s2 != "0"){
			if (s1.length() >= s2.length())
				s1 = add(s1, s2);
			else
				s1 = add(s2, s1);
		}
		int index = 0;
		cout << s1<< endl;;
		stop:
		if (n)
			cout << endl;
	}
	return 0;
	
}