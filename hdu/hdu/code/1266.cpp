#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
bool fun(char c){
	return c >= '1'&&c <= '9';
}
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	string s;
	cin >> N;
	while (N--){
		cin >> s;
		int len = s.length();
		int a, b;
		
		for (a = 0; a < len;++a)
		if (fun(s[a]))break;
		for (b = len - 1; b >= 0;--b)
		if (fun(s[b]))break;
		while (a < b){
			char c = s[a];
			s[a] = s[b];
			s[b] = c;
			a++;
			b--;
		}
		cout << s << endl;
	}


	return 0;
}