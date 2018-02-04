#include <iostream>
#include <string>
//#include <fstream>
#include <map>
using namespace std;
int main(){
	//ifstream in("C:\\temp.txt");
	map<string, int> msi;
	msi["one"] = 1;
	msi["two"] = 2;
	msi["three"] = 3;
	msi["four"] = 4;
	msi["five"] = 5;
	msi["six"] = 6;
	msi["seven"] = 7;
	msi["eight"] = 8;
	msi["nine"] = 9;
	msi["zero"] = 0;
	string s;
	int a, b;
	while (cin >> s){
		a = b = 0;
		a = msi[s];
		while (cin >> s&&s != "+")a = a * 10 + msi[s];
		while (cin >> s&&s != "=")b = b * 10 + msi[s];
		if (a + b == 0)break;
		cout << a + b << endl;
	}


	return 0;
}