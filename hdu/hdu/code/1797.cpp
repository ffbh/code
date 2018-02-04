#include <iostream>
#include <string>
#include <fstream>
using namespace std;
char data;
int num;
char TAR;
bool Ok;
bool OK(int index){
	if (index == 0)
		return data == 'a'&&num >= 1;
	else if (index == 1)
		return data == 'b'&&num == 1;
	else if (index == 2){
		return data == 'a'&&num == 1;
	}
	else if (index == 3){
		if (data == 'b' || data == 'd'){
			if (data == 'b'){
				TAR = 'd';
				return num == 0 || num == 1;
			}
			else{
				TAR = 'h';
				return num >= 1;
			}
		}
		else {
			Ok = 1;
			return data == 'h'&&num == 1;
		}
	}
	else {
		if (TAR){
			if (TAR != data)
				return 0;
			if (TAR == 'd'){
				TAR = 'h';
				return num >= 1;
			}
			else{
				Ok = 1;
				return num == 1;
			}
		}
		else{
			return num >= 1 && (data == 'k' || data == 'f');
		}
	}
	return 0;
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int size;
	while (T--){
		string s;
		Ok = 0;
		cin >> s;
		size = 0;
		data = s[0];
		num = 0;
		bool flag;
		for (int i = 0; i < s.length(); ++i){
			if (data == s[i])
				num++;
			else{
				if (!(flag = OK(size)))
					break;
				if (Ok){
					for (int j = i; j < s.length();++j)
					if (s[j] != 'k' && s[j] != 'f'){
						flag = 0;
						break;
					}
					i = s.length();
				}
				size++;
				data = s[i];
				num = 1;
			}
		}
		if (flag&&Ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}