#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int h[256];
string s;
void Init(){
	for (char c = '0'; c <= '9'; ++c)
		h[c] = c - '0';
	for (char c = 'A'; c <= 'Z'; ++c)
		h[c] = c - 'A' + 10;
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	cin >> s;
	int min_k = 2;
	for (int i = 0; i < s.length(); ++i)
		min_k = max(min_k, h[s[i]] + 1);
	int k;
	for (k = min_k; k <= 36; ++k){
		int r = 0;
		for (int j = 0; j < s.length(); ++j){
			r = (r * k + h[s[j]]) % (k - 1);
		}
		if (r == 0){
			break;
		}
	}

	if (k <= 36)
		cout << k << endl;
	else
		cout << "No solution." << endl;


	return 0;
}