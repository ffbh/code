#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
char ans[20];

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	string s;
	int g = 34943;
	for (int i = 0; i < 10; ++i)
		ans[i] = i + '0';
	for (int i = 10; i < 16; ++i)
		ans[i] = 'A' + i - 10;
	while (getline(in, s) && s[0] !='#'){
		int m = 0;
		for (int i = 0; i < s.length(); ++i)
			m = (m * 256 + s[i]) % g;
		for (int i = 0; i < 2; ++i){
			m = (m * 256) % g;
		}
		int p = (g - m) % g;
		int d1 = p / 256;
		int d2 = p % 256;
		cout << ans[d1 / 16] << ans[d1 % 16];
		cout << " ";
		cout << ans[d2 / 16] << ans[d2 % 16] << endl;
	}



	return 0;
}