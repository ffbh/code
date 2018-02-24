#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string s;

int ISQ(int x){
	if (x < 0||s[x] == '0') return x;
	return ISQ(ISQ(x - 1) - 1);
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		cin >> s;
		int d = s.length();
		while ((d = ISQ(d - 1)) > 0);
		if (d)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}