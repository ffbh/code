#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
bool Init(string& s){
	int num = 0;
	for (int i = 0; i < s.length();++i)
	if (s[i] == '.'){
		num++;
		s[i] = ' ';
	}
	else if (s[i] < '0' || s[i]>'9')
		return 0;
	return num==3;
}


int main(){
	ifstream in("C:\\temp.txt");
	string s;
	stringstream ss;
	while (getline(cin, s)){
		if (!Init(s)){
			cout << "NO" << endl;
			continue;
		}
		ss.clear();
		ss.str(s);
		int num = 4;
		bool flag = 1;
		while (ss >> s){
			num--;
			int temp = 0;
			for (int i = 0; i < s.length(); ++i){
				temp = temp * 10 + s[i] - '0';
				if (temp>255){
					flag = 0;
					break;
				}
			}

		}
		if (flag&&!num)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}