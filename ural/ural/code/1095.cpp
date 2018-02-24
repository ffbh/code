#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int num[12], tmp[4];
int Mod(){
	for (int i = 1; i <= 4; ++i)
		num[i]--;
	int mod = 0;
	for (int i = 1; i < 10;++i)
	for (int j = 1; j <= num[i]; ++j)
		mod = (mod * 10 + i) % 7;
	
	return mod;
}
void cale(int mod){
	for (int i = 0; i < 4; ++i)
		tmp[i] = i + 1;
	while (1){
		int k = mod;
		for (int i = 0; i < 4; ++i)
			k = (k * 10 + tmp[i]) % 7;
		for (int j = 1; j <= num[0]; ++j)
			k = (k * 10) % 7;
		if (k == 0)
			break;
		next_permutation(tmp, tmp + 4);
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		memset(num, 0, sizeof(num));
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); ++i)
			num[s[i] - '0']++;
		cale(Mod());
		for (int i = 1; i < 10; ++i)
		for (int j = 1; j <= num[i]; ++j)
			printf("%d", i);
		for (int i = 0; i < 4; ++i)
			printf("%d", tmp[i]);
		for (int j = 1; j <= num[0]; ++j)
			putchar('0');
		cout << endl;
	}
	return 0;
}