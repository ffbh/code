#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
bool ok[15];
int w[15];


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		memset(ok, 0, sizeof(ok));
		memset(w, 0, sizeof(w));
		for (int k = 0; k < 3; ++k){
			string s1, s2, s3;
			cin >> s1 >> s2 >> s3;
			if (s3[0] == 'e'){
				for (int i = 0; i < s1.length(); ++i){
					ok[s1[i] - 'A'] = 1;
					ok[s2[i] - 'A'] = 1;
				}
			}
			else if (s3[0] == 'u'){
				for (int i = 0; i < s1.length(); ++i){
					w[s1[i] - 'A']++;
					w[s2[i] - 'A']--;
				}
			}
			else{
				for (int i = 0; i < s1.length(); ++i){
					w[s1[i] - 'A']--;
					w[s2[i] - 'A']++;
				}
			}
		}
		int u;
		int mmax = -1;
		for (int i = 0; i < 12;++i)
		if (!ok[i] && abs(w[i])>mmax){
			u = i;
			mmax = abs(w[i]);
		}
		if (w[u] < 0)
			printf("%c is the counterfeit coin and it is light.\n", char(u + 'A'));
		else
			printf("%c is the counterfeit coin and it is heavy.\n", char(u + 'A'));
	}
	return 0;
}