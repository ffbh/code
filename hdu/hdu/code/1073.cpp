#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
string s1[5002];
string s2[5002];
string ss1, ss2;
bool Baccept(int len){
	bool flag = 1;
	for (int i = 0; i < len; ++i)
		if (s1[i] != s2[i]){
			flag = 0;
			break;
		}
	return flag;
}
void CleanBlankS1(int len){
	ss1 = "";
	for (int i = 0; i < len; ++i){
		int length = s1[i].length();
		for (int j = 0; j < length; ++j)
		if (s1[i][j] != ' '&&s1[i][j] != '\t'&&s1[i][j] != '\n')
			ss1 += s1[i][j];
	}
}
void CleanBlankS2(int len){
	ss2 = "";
	for (int i = 0; i < len; ++i){
		int length = s2[i].length();
		for (int j = 0; j < length; ++j)
			if (s2[i][j] != ' '&&s2[i][j] != '\t'&&s2[i][j] != '\n')
				ss2 += s2[i][j];
	}

}
int main(){
//	ifstream in("C:\\temp.txt");
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	while (n--){
		getline(cin, s);
		int len1 = 0;
		while (getline(cin, s1[len1]) && s1[len1] != "END")len1++;
		getline(cin, s);
		int len2 = 0;
		while (getline(cin, s2[len2]) && s2[len2] != "END")len2++;
		
		if (len1 == len2&&Baccept(len1)){
				cout << "Accepted"<<endl;
				continue;
		}
		CleanBlankS1(len1+1);
		CleanBlankS2(len2+1);
		if (ss1==ss2)
			cout << "Presentation Error" << endl;
		else cout << "Wrong Answer" << endl;
	}




	return 0;
}