#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;
string s;
map<char, int> msi;
int getNum(){
	int data[1010];
	int sum = 0;
	for (int i = 0; i < s.length(); ++i)
		data[i] = msi[s[i]];
	for (int i = 1; i < s.length();++i)
	if (data[i]>data[i - 1])
		sum -= data[i - 1];
	else
		sum += data[i - 1];
	sum += data[s.length() - 1];
	return sum;
}


int main(){
	ifstream in("C:\\temp.txt");
	msi['I'] = 1;
	msi['V'] = 5;
	msi['X'] = 10;
	msi['L'] = 50;
	msi['C'] = 100;
	msi['D'] = 500;
	msi['M'] = 1000;
	int T;
	cin >> T;
	while (T--){
		cin >> s;
		cout << getNum() << endl;
	}







	return 0;
}