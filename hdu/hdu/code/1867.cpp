#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int next1[100100];
int len1;
int next2[100100];
int len2;
string s1, s2;
void Init(){
	int i, j;
	i = 0;
	j = -1;
	next1[0] = -1;
	while (i < len1){
		if (j == -1 || s1[i] == s1[j])
			next1[++i] = ++j;
		else
			j = next1[j];
	}
	i = 0;
	j = -1;
	next2[0] = -1;
	while (i < len2){
		if (j == -1 || s2[i] == s2[j])
			next2[++i] = ++j;
		else
			j = next2[j];
	}
}

string fun1(){
	int i, j;
	j = 0;
	if (len2 >= len1)
		i = 0;
	else
		i = len1 - len2;
	while (i < len1){
		if (j == -1 || s1[i] == s2[j]){
			++i;
			++j;
		}
		else j = next2[j];
	}
	return s1.substr(0, len1 - j) + s2;
}

string fun2(){
	int i, j;
	j = 0;
	if (len1 >= len2)
		i = 0;
	else
		i = len2 - len1;
	while (i < len2){
		if (j == -1 || s2[i] == s1[j]){
			++i;
			++j;
		}
		else j = next1[j];
	}
	return s2.substr(0, len2 - j) + s1;
}

int main(){
	//ifstream in("C:\\temp.txt");
	
	while (cin >> s1 >> s2){
		len1 = s1.length();
		len2 = s2.length();
		Init();
		string ans1 = fun1();
		string ans2 = fun2();
		if (ans1.length() != ans2.length()){
			if (ans1.length() < ans2.length())
				cout << ans1 << endl;
			else
				cout << ans2 << endl;
		}
		else{
			if (ans1 < ans2)
				cout << ans1 << endl;
			else
				cout << ans2 << endl;
		}
	}





	return 0;
}