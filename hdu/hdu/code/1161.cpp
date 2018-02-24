#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
bool fun(char c){
	return c >= 'A'&&c <= 'Z';
}
int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	while (getline(cin, s)){
		int len = s.length();
		for (int i = 0; i < len;++i)
		if (fun(s[i]))
			printf("%c", char(s[i] + 'a' - 'A'));
		else printf("%c", s[i]);
		cout << endl;
	}


	return 0;
}