#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
map<char, char> mcc;
string s;
void Init(){
	mcc['A'] = 'A';
	mcc['E'] = '3';
	mcc['3'] = 'E';
	mcc['H'] = 'H';
	mcc['I'] = 'I';
	mcc['J'] = 'L';
	mcc['L'] = 'J';
	mcc['M'] = 'M';
	mcc['O'] = 'O';
	mcc['S'] = '2';
	mcc['2'] = 'S';
	mcc['T'] = 'T';
	mcc['U'] = 'U';
	mcc['V'] = 'V';
	mcc['W'] = 'W';
	mcc['X'] = 'X';
	mcc['Y'] = 'Y';
	mcc['Z'] = '5';
	mcc['5'] = 'Z';
	mcc['1'] = '1';
	mcc['8'] = '8';
}

bool Ispalindrome(){
	int L = 0;
	int R = s.length() - 1;
	while (L < R){
		if (s[L] != s[R])
			return 0;
		L++;
		R--;
	}
	return 1;
}
bool Ismirrored(){
	int L = 0;
	int R = s.length() - 1;
	while (L <= R){
		if (mcc[s[L]] != s[R])
			return 0;
		L++;
		R--;
	}
	return 1;
}

int main(){
	ifstream in("C:\\temp.txt");
	Init();
	while (cin >> s){
		bool b1 = Ispalindrome();
		bool b2 = Ismirrored();
		if (b1){
			if (b2)
				printf("%s -- is a mirrored palindrome.\n", s.c_str());
			else
				printf("%s -- is a regular palindrome.\n", s.c_str());
		}
		else{
			if (b2)
				printf("%s -- is a mirrored string.\n", s.c_str());
			else
				printf("%s -- is not a palindrome.\n", s.c_str());
		}
		cout << endl;


	}
	return 0;
}