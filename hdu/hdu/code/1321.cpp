#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
int main(){
	//ifstream in("C:\\temp.txt");
	int N;
	string s;
	cin >> N;
	getchar();
	while (N--){
		getline(cin, s);
		int len = s.length();
		for (int i = len - 1; i >= 0; --i)
			printf("%c", s[i]);
		cout << endl;
	
	}

	return 0;
}