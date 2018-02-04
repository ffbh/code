#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	map<char, char> mcc;
	mcc['b'] = ' ';
	mcc['q'] = ',';
	mcc['t'] = '!';
	mcc['m'] = 'l';
	mcc['i'] = 'e';
	mcc['c'] = 'a';
	mcc['a'] = 'c';
	mcc['e'] = 'i';
	mcc['l'] = 'm';
	string s;
	while (getline(cin, s)){
		for (int i = 0; i < s.length();++i)
		if (mcc[s[i]])
			cout << mcc[s[i]];
		else
			cout << s[i];
		cout << endl;
	}
	return 0;
}