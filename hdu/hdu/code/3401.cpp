#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
string s;
int main(){
	ifstream in("C:\\input.txt");
	cin >> s;
	bool f = 0;
	for (int i = 0; i < s.length()-2; ++i){
		if (s[i] == s[i + 2]){
			f = 1;
			break;
		}
	}
	if (!f){
		cout << s.length() << endl;
	}
	else{
		int len = s.length();
		if (len % 2)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
	
	
















	return 0;
}