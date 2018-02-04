#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
//	ifstream in("C:\\temp.txt");
	string s;
	int N;
	cin >> N;
	int CASE = 1;
	while (N--){
		cin >> s;
		int len = s.length();
		for (int i = 0; i < len;++i)
		if (s[i] == 'Z')
			s[i] = 'A';
		else
			s[i] = char(s[i] + 1);
		printf("String #%d\n", CASE++);
		cout << s << endl<<endl;
	
	
	}

	return 0;
}