#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string s;
int fun(char c){
	if (c >= '0'&&c <= '9')
		return c - '0';
	if (c >= 'a'&&c <= 'f')
		return c - 'a' + 10;
	return -1;
}

bool dfs(int pos, int base){
	if (pos == s.length())
		return 1;
	if (base > 16 || base < 2)return 0;
	if (s[pos] == '#')
		pos++;
	else
		return 0;
	int sum = 0;
	bool ok = 0;
	while (1){
		if (pos == s.length())return 0;
		if (s[pos] == '#')break;
		int temp = fun(s[pos]);
		if (temp == -1 || temp >= base)
			return 0;
		sum = sum*base + temp;
		if (sum > 16)
			sum = 17;
		ok = 1;
		pos++;
	}
	if (!ok)return 0;
	return dfs(pos + 1, sum);
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int f;
	while (T--){
		cin >> s;
		f = 0;
		if (s[0]>'9' || s[0]<'0'){
			cout << "no" << endl;
			continue;
		}
		for (int i = 0; i < s.length(); ++i)
		if (s[i]<'0' || s[i]>'9'){
			f = i + 1;
			break;
		}
		if (f){
			f--;
			int sum = 0;
			for (int i = 0; i < f; ++i){
				sum = sum * 10 + s[i] - '0';
			}
			if (dfs(f, sum))
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		else
			cout << "yes" << endl;
	}
	return 0;
}

