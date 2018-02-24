#include<iostream>
#include <string>
//#include <fstream>
using namespace std;

bool bVowel(char c){
	return c == 'a' || c == 'e' ||
		c == 'i' || c == 'o' || c == 'u';
}

int main(){
	string s;
	int length;
	bool flag;
	//ifstream in("C:\\temp.txt");
	while (cin >> s&&s != "end"){
		length = s.length();
		char *p = new char[length];
		if (!p) exit(0);
		int i = 0;
		flag = 0;
		while (i < length){
			if (bVowel(s[i])){
				p[i] = 'a';
				flag = 1;
			}
			else
				p[i] = 'b';
			++i;
		}
		if (!flag) {
			cout << "<" << s << ">" << " is not acceptable." << endl;
			continue;
		}
		string temp(p);
		int index1 = temp.find("aaa");
		int index2 = temp.find("bbb");
		if (index1!=s.npos||index2!=s.npos){
			cout << "<" << s << ">" << " is not acceptable." << endl;
			continue;
		}
		i = 1;
		char old = s[0];
		flag = 1;
		while (i < length){
			if (s[i] == old)
			if (old != 'e')
			if (old != 'o'){
				flag = 0;
				break;
			}
			old = s[i];
			++i;
		}
		if (!flag)
			cout << "<" << s << ">" << " is not acceptable." << endl;
		else
			cout << "<" << s << ">" << " is acceptable." << endl;
		delete[] p;
	}


}


