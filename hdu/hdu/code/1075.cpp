#include <iostream>
#include <string>
#include <map>
//#include <fstream>
using namespace std;

bool fun(char c){
	return c <= 'z'&&c >= 'a' || c <= 'Z'&&c >= 'A';
}
int main(){
	//ifstream in("C:\\temp.txt");
	map<string, string> mss;
	string s1,s2;
	cin>>s1;
	while(1){
		cin >> s1 >> s2;
		if (s1 == "END")
			break;
		mss[s2] = s1;
	} 
	getline(cin, s1);
	int pos1, pos2; 
	while (pos1 = 0, getline(cin, s1) && s1 != "END"){
		int len = s1.length();
		while (1){
			while (pos1<len&&!fun(s1[pos1]))
				printf("%c", s1[pos1++]);
			if (pos1 >= len)
				break;
			pos2 = pos1;
			while (pos1 < len&&fun(s1[pos1]))pos1++;
			s2 = s1.substr(pos2, pos1 - pos2);
			if (mss[s2] == "")
				cout << s2;
			else
				cout << mss[s2];
		}
		cout << endl;


	}
		

	return 0;

}