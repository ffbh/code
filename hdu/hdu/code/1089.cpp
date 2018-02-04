#include <iostream>
//#include <fstream>
#include <string>
using namespace std;
string s1, s2;
string add( string& s1,  string& s2){
	int len1 = s1.length();
	int len2 = s2.length();
	string temp=s1,temp1=s2;
	if (len1 != len2){
		if (len1 > len2){
			for (int i = 0; i < len1 - len2; ++i)
				s2 = "0" + s2;
			temp = s1;
			temp1 = s2;
		}
		else{
			for (int i = 0; i < len2 - len1; ++i)
				s1 = "0" + s1;
			temp = s2;
			temp1 = s1;
		}
	}
	
	int len = temp.length();
	for (int i = 0; i < len; ++i)
		temp[i] += temp1[i] - '0';
	int flag = 0;
	for (int i = len - 1; i >= 0; --i){
		temp[i] += flag;
		if (temp[i]>'9'){
			temp[i] -= 10;
			flag = 1;
		}
		else flag = 0;
	}
	if (flag)
		temp = "1" + temp;
	return temp;

}
int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> s1 >> s2){
		cout << add(s1, s2) << endl;
	}

	return 0;
}