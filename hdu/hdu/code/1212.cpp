#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
int main(){
//	ifstream in("C:\\temp.txt");
	string s;
	int m;
	while (cin >> s >> m){
		int len = s.length();
		int ans = 0;
		for (int i = 0; i < len; ++i){
			ans = (ans*10  + s[i]-'0') % m;
		}
		cout << ans << endl;
	
	}

	return 0;
}