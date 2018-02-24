#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;
map<string, int> msi;
string s;
void Init(){
	for (int i = 0; i < s.length();++i)
	if (s[i]<'A' || s[i]>'Z')
		s[i] = ' ';
}


int main(){
	msi["int"] = 1;
	msi["real"] = 2;
	msi["char"] = 3;
	ifstream in("C:\\temp.txt");
	while (1){
		for (int i = 0; i < 30;++i)

		while (cin >> s&&s[0]!='-'){
			Init();
			char m, c;







		}






	}








	return 0;
}