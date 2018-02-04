#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool bLetter(char c){
	return c >= 'A'&&c <= 'Z';
}

char fun(char c){
	if (!bLetter(c)) return c;
	if (c <= 'E') return c + 'Z' - 'E';
	else return  c - ('F' - 'A');

}
int main(){
//	ifstream in("C:\\temp.txt");
	string s1,s2;
	while (getline(cin, s1)&&s1 != "ENDOFINPUT"){
		while (getline(cin,s2)&&s2!="END"){
			int len = s2.length();
			for (int i = 0; i < len; ++i)
				s2[i] = fun(s2[i]);
			
			cout << s2 <<endl;
		}
	


	}


	return 0;
}