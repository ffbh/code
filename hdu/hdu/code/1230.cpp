#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>
using namespace std;
int a[30], b[30];
int ans[30];
int prime[30] = {0, 2, 3, 5, 7, 11, 
				13, 17, 19, 23, 29, 
				31, 37, 41, 43, 47,
				53, 59, 61, 67, 71, 
				73, 79, 83, 89, 97,999,999,999,999 };


int CLEAR(string& s){
	int len = s.length();
	int res = 1;
	for (int i = 0; i < len;++i)
	if (s[i] == ','){
		res++;
		s[i] = ' ';
	}
	return res;
}
int main(){
		ifstream in("C:\\temp.txt");
	string s1, s2;
	stringstream ss;
	while (in >> s1 >> s2){
		if (s1 == "0"&&s2 == "0")break;
		memset(ans, 0, sizeof(ans));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int lenS1 = CLEAR(s1);
		ss.clear();
		ss.str(s1);
		for (int i = lenS1; i >= 1; --i)
			ss >> a[i];
		int lenS2 = CLEAR(s2);
		ss.clear();
		ss.str(s2);
		for (int i = lenS2; i >= 1; --i)
			ss >> b[i];

		for (int i = 1; i < 27; ++i){
			ans[i] += a[i] + b[i];
			if (ans[i] >= prime[i]){
				ans[i] -= prime[i];
				ans[i + 1]++;
			}
		}
		int k;
		for (int i = 29; i >= 1;--i)
		if (ans[i]){
			k = i;
			break;
		}
		while (k >= 2)printf("%d,", ans[k--]);
		cout << ans[1] << endl;


	}




	return 0;
}




