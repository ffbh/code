#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	string s;
	int CASE = 1;
	while (cin >> s&&s != "STOP"){
		int L, R;
		L = 0;
		R = s.length() - 1;
		bool flag = 1;
		while (L < R){
			if (s[L] != s[R]){
				flag = 0;
				break;
			}
			L++;
			R--;
		}
		if (flag)
			printf("#%d: YES\n", CASE++);
		else
			printf("#%d: NO\n", CASE++);

	}





	return 0;
}