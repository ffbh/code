#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
string s;
int h[255];


bool judge(char c){
	return c != 'h'&&c != 'i'&&c != 'o';
}
int main(){
	ifstream in("C:\\input.txt");
	while (cin >> s){
		memset(h, 0, sizeof(h));
		int ans = -1;
		int spos = 0, epos = 0;
		while (epos < s.length()){
			while (epos < s.length()){
				char c = s[epos];
				h[c]++;
				if (c == 'h'){
					if (h['h'] == 2 && h['i'] == 1 && h['o'] == 1){
						while (spos < epos && judge(s[spos])){
							spos++;
						}
						if (ans == -1 || ans > epos - spos + 1){
							ans = epos - spos + 1;
						}
					}

					if (h[c] > 2){
						while (spos < epos && s[spos] != c){
							h[s[spos]]--;
							spos++;
						}
						spos++;
						h[c]--;
					}

				}
				else if (c == 'i' || c=='o'){
					if (h['h'] == 2 && h['i'] == 1 && h['o'] == 1){
						while (spos < epos && judge(s[spos])){
							spos++;
						}
						if (ans == -1 || ans > epos - spos + 1){
							ans = epos - spos + 1;
						}
					}

					if (h[c] > 1){
						while (spos < epos && s[spos] != c){
							h[s[spos]]--;
							spos++;
						}
						spos++;
						h[c]--;
					}

				}
				if (h['h'] == 2 && h['i'] == 1 && h['o'] == 1){
					while (spos < epos && judge(s[spos])){
						spos++;
					}
					if (ans == -1 || ans > epos - spos + 1){
						ans = epos - spos + 1;
					}
				}
				epos++;
			}

		}
		
		cout << ans << endl;

	}

	return 0;
}