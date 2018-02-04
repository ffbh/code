#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s1, s2;
int Next[100010];
void Init(){
	int i, j;
	i = 0;
	j = -1;
	Next[0] = -1;
	while (i < s2.length()){
		if (j == -1 || s2[i] == s2[j])
			Next[++i] = ++j;
		else
			j = Next[j];
		i++;
	}
}

bool kmp(){
	int i, j;
	i = j = 0;
	bool sign = 1;
	while (sign || i < s1.length()){
		if (i == s1.length()){
			i = 0;
			sign = 0;
		}
		if (j==-1||s1[i] == s2[j]){
			i++;
			j++;
		}
		else
			j = Next[j];
		if (j == s2.length())
			return 1;
	}
	return 0;
}


int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> s1 >> s2){
		if (s1.length() < s2.length()){
			cout << "no" << endl;
			continue;
		}
		Init();
		if (kmp())
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}
	return 0;
}