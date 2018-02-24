#include <iostream>
#include <string>
#include <fstream>
#include<map>
using namespace std;
void fun(char& c){
	if (c >= 'a'&&c <= 'f')
		c -= 32;
}
int main(){
//	ifstream in("C:\\temp.txt");
	map<char, int> mci;
	mci['0'] = 0;
	mci['1'] = 1;
	mci['2'] = 2;
	mci['3'] = 3;
	mci['4'] = 4;
	mci['5'] = 5;
	mci['6'] = 6;
	mci['7'] = 7;
	mci['8'] = 8;
	mci['9'] = 9;
	mci['A'] = 10;
	mci['B'] = 11;
	mci['C'] = 12;
	mci['D'] = 13;
	mci['E'] = 14;
	mci['F'] = 15;
	string s;
	int n, m;
	int Ten;
	char temp[1000];
	while (cin >> s >> n >> m){
		int len = s.length();
		Ten = 0;
		for (int i = 0; i < len; ++i)
			Ten = Ten * n + mci[s[i]];
		itoa(Ten, temp, m);
		s = temp;
		len = s.length();
		for (int i = 0; i<len; ++i)
			fun(temp[i]);
		if (s.length()>7)
			printf("  ERROR\n");
		else
			printf("%7s\n", temp);
		
	}



	return 0;
}