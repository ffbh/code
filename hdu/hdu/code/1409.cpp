#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s;
bool IsNumber(char c){
	return c >= '0'&&c <= '9';
}
bool OkE(int pos){
	pos++;
	if (s[pos] == '+' || s[pos] == '-')
		pos++;
	if (pos == s.length())
		return 0;
	while (pos<s.length())
	if (!IsNumber(s[pos++]))
		return 0;
	return 1;
}


bool Okdian(int pos){
	for (pos++; pos < s.length(); pos++){
		if (s[pos] == 'e' || s[pos] == 'E')
			return OkE(pos);
		if (!IsNumber(s[pos]))
			return 0;
	}
	return 1;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	cin.get();
	while (T--){
		bool flag = 1;
		getline(cin, s);
		if (s[0] == '+' || s[0] == '-' || IsNumber(s[0])){
			int pos = 1;
			while (pos < s.length() && IsNumber(s[pos])) pos++;
			if (pos != s.length()){
				if (s[pos] == '.')
					flag = Okdian(pos);
				else if (s[pos] == 'e' || s[pos] == 'E')
					flag = OkE(pos);
				else
					flag = 0;
			}
		}
		else if (s[0] == '.')
			flag = Okdian(0);
		else
			flag = 0;
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}