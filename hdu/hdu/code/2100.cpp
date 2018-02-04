#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void add(string& s1, string& s2){
	int i, j;
	i = s1.length();
	j = s2.length();
	bool flag = 0;
	while (i >= 0 && j >= 0){
		if (flag)
			s1[i]++;
		s1[i] += s2[j] - 'A';
		if (s1[i] > 'Z'){
			flag = 1;
			s1[i] -= 26;
		}
		else flag = 0;
		i--;
		j--;
	}
	while (i >= 0&&flag){
		if (flag)
			s1[i]++;
		if (s1[i] > 'Z'){
			flag = 1;
			s1[i] -= 26;
		}
		else flag = 0;
		i--;
	}
	if (flag)
		cout << 'B';
	cout << s1 << endl;
}

int main(){
	//ifstream in("C:\\temp.txt");
	string s1, s2;
	while (cin >> s1 >> s2){
		int i = 0;
		while (i < s1.length() && s1[i] == 'A')i++;
		if (i)
			s1 = s1.substr(i);
		i = 0;
		while (i < s2.length() && s2[i] == 'A')i++;
		if (i)
			s2 = s2.substr(i);
		if (s1.length()>s2.length())
			add(s1, s2);
		else
			add(s2, s1);
	}
	return 0;
}