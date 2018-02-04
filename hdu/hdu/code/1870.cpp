#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	string s;
	while (cin >> s){
		int dd = 0;
		int res = INT_MAX;
		for (int i = 0; i < s.length();++i)
		if (s[i] == '(')
			dd++;
		else if (s[i] == ')')
			dd--;
		else if (res>dd)
			res = dd;
		cout << res << endl;

	}





	return 0;
}