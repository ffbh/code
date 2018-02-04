#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	cin.get();
	int tab, trailing;
	string s;
	while (T--){
		tab = trailing = 0;
		while (getline(cin, s)&&s!="##"){
			for (int i = 0; i < s.length();++i)
			if (s[i] == '\t')
				tab++;
			for (int i = s.length() - 1; i >= 0;--i)
			if (s[i] == ' ')
				trailing++;
			else if (s[i] == '\t')
				trailing += 4;
			else
				break;
		}
		printf("%d tab(s) replaced\n", tab);
		printf("%d trailing space(s) removed\n",trailing);
	}
	return 0;
}