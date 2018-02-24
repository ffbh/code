#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	map<char, int> msi;
	char c;
	for (int i = 0, c = '0'; i <= 9; ++i, ++c)
		msi[c] = i;
	for (int i = 10, c = 'A'; i <= 15; ++i, ++c){
		msi[c] = i;
		msi[c + 32] = i;
	}
	string s1, s2;
	while (cin >> s1 >> s2){
		int a, b;
		a = b = 0;
		int la = s1.length();
		int lb = s2.length();
		for (int i = 0; i < la; ++i)
			a = a * 16 + msi[s1[i]];
		for (int i = 0; i < lb; ++i)
			b = b * 16 + msi[s2[i]];
		cout << a + b << endl;
	}
	
	return 0;
}