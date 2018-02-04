#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	string s1,s2;
	while (getline(cin, s1)&&s1 != "#"){
		getline(cin, s2);
		for (int i = 0; i < s1.length(); ++i){
			int ans = 0;
			for (int j = 0; j < s2.length();++j)
			if (s1[i] == s2[j])
				++ans;
			printf("%c %d\n", s1[i], ans);
		}
	}
	return 0;
}