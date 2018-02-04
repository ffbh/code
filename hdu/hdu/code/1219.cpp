#include <iostream>
#include <string>
//#include <fstream>
#include <map>
using namespace std;
int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	map<char, int> mci;
	int k = 0;
	while (getline(cin, s)){
		//	if (k != 0)
		//		printf("\n");
		//	k = 1;
		mci.clear();
		int len = s.length();
		for (int i = 0; i < len; ++i)
			mci[s[i]]++;
		for (char i = 'a'; i <= 'z'; ++i)
			printf("%c:%d\n", i, mci[i]);
		printf("\n");

	}

	return 0;
}