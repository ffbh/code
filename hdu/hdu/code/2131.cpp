#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	char c;
	string s;
	while (cin >> c >> s){
		if (c >= 'a'&&c <= 'z')
			c -= 32;
		int num = 0;
		for (int i = 0; i < s.length();++i)
		if (c == s[i] || c == s[i] - 32)
			num++;
		printf("%.5f\n", double(num) / s.length());

	}





	return 0;
}