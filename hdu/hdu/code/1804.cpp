#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

bool fu(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main(){
	//    ifstream in("C:\\temp.txt");
	int N, M;
	map<string, string> mss;
	while (cin >> N >> M){
		mss.clear();
		while (N--){
			string s1, s2;
			cin >> s1 >> s2;
			mss[s1] = s2;
		}
		while (M--){
			string s;
			cin >> s;
			if (mss[s].size())
				cout << mss[s] << endl;
			else{
				int len = s.length();
				if (s[len - 1] == 'y'){
					if (len >= 2 && !fu(s[len - 2])){
						s[len - 1] = 'i';
						s += "es";
					}
					else
						s += 's';
				}
				else if (s[len - 1] == 'o' || s[len - 1] == 's'
					|| s[len - 1] == 'x')
					s += "es";
				else if (len >= 2 && s[len - 1] == 'h' && (s[len - 2] == 'c' || s[len - 2] == 's'))
					s += "es";
				else
					s += 's';
				cout << s << endl;
			}
		}





	}





	return 0;
}