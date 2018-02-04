#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s1, s2;
int Next1[1000010];
int Next2[1000010];

void Init(){
	int i, j;
	Next1[0] = -1;
	i = 0;
	j = -1;
	while (i < s1.length()){
		if (j == -1 || s1[i] == s1[j])
			Next1[++i] = ++j;
		else
			j = Next1[j];
	}
	i = 0;
	j = -1;
	Next2[0] = -1;
	while (i < s2.length()){
		if (j == -1 || s2[i] == s2[j])
			Next2[++i] = ++j;
		else
			j = Next2[j];
	}
}

int kmp1(){
	int i, j;
	i = j = 0;
	while (i < s1.length()){
		if (j == -1 || s1[i] == s2[j]){
			++i;
			++j;
		}
		else
			j = Next2[j];
		if (j == s2.length())
			break;
	}
	return s1.length() + s2.length() - j;
}

int kmp2(){
	int i, j;
	i = j = 0;
	while (i < s2.length()){
		if (j == -1 || s2[i] == s1[j]){
			++i;
			++j;
		}
		else
			j = Next1[j];
		if (j == s1.length())
			break;
	}
	return s2.length() + s1.length() - j;
}

int min(int a, int b){
	return a < b ? a : b;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> s1 >> s2;
		Init();
		cout << min(kmp1(),kmp2()) << endl;
	}
	return 0;
}