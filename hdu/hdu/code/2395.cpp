#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

int fun(int a, int b, int base){
	int k1 = abs(a - b);
	int k2 = abs(min(a, b) + base - max(a, b));
	return min(k1, k2);
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	string s1, s2;
	cin >> T;
	while (T--){
		cin >> s1 >> s2;
		int h1, m1, h2, m2, c1, c2;
		h1 = m1 = h2 = m2 = 0;
		int pos = 0;
		while (pos < s1.length() && s1[pos] >= '0'&&s1[pos] <= '9'){
			h1 = h1 * 10 + s1[pos] - '0';
			pos++;
		}
		pos++;
		while (pos < s1.length() && s1[pos] >= '0'&&s1[pos] <= '9'){
			m1 = m1 * 10 + s1[pos] - '0';
			pos++;
		}
		c1 = s1[pos];

		pos = 0;
		while (pos < s2.length() && s2[pos] >= '0'&&s2[pos] <= '9'){
			h2 = h2 * 10 + s2[pos] - '0';
			pos++;
		}
		pos++;
		while (pos < s2.length() && s2[pos] >= '0'&&s2[pos] <= '9'){
			m2 = m2 * 10 + s2[pos] - '0';
			pos++;
		}
		c2 = s2[pos];
		int ans = 0;
		if (c1 != c2)
			ans++;
		ans += fun(h1, h2, 12);
		ans += fun(m1 % 10, m2 % 10, 10);
		ans += fun(m1 / 10, m2 / 10, 6);
		if (ans == 1)
			printf("Going from %s to %s requires %d push.\n", s1.c_str(), s2.c_str(), ans);
		else
			printf("Going from %s to %s requires %d pushes.\n", s1.c_str(), s2.c_str(), ans);
	}
	return 0;
}