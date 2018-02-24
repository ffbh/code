#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		string s;
		cin >> s;
		s += '0';
		int num = 1;
		for (int i = 1; i < s.length(); ++i){
			if (s[i] == s[i - 1])
				num++;
			else{
				if (num != 1)
					printf("%d%c", num, s[i - 1]);
				else
					putchar(s[i - 1]);
				num = 1;
			}
		}
		cout << endl;
	}







	return 0;
}