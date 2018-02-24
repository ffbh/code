#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	string s;
	cin >> T;
	int CASE = 1;
	while (T--){
		int k;
		cin >> k >> s;
		s[k - 1] = 0;
		printf("%d ", CASE++);
		for (int i = 0; i < s.length();++i)
		if (s[i])
			putchar(s[i]);
		cout << endl;
	}
	return 0;
}