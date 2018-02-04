#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	string s;
	while (cin >> s){
		int len = s.length();
		int ans = 0;
		int l, r;
		for (int i = 0; i < len; ++i){
			l = i - 1;
			r = i + 1;
			while (l >= 0 && r < len&&s[l] == s[r]){
				ans++;
				l--;
				r++;
			}
			l = i - 1;
			r = i;
			while (l >= 0 && r < len&&s[l] == s[r]){
				ans++;
				l--;
				r++;
			}
		}
		cout << ans + len << endl;



	}

	return 0;
}